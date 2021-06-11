#include<Windows.h>
#include<fstream>
#include<stdlib.h>
#include<time.h>

using namespace std;

#define PRODUCER 'P'		//������
#define CONSUMER 'C'		//������
#define INTE_PER_SEC 1000	//ÿ��ʱ���ж���Ŀ
#define MAX_THREAD_NUM 64	//����߳���
#define BUF_SIZE 2			//��������С

//��ʱʱ��60000ms(�����һ���̴߳�����ʼ���������ʱ��60s��
//��Ȼ���������߳�ȡ���������������̷߳Ų���������ô�����߳�
#define TIMEOUT 20000		

struct ThreadInfo
{
	int  serial;		//�߳����
	char  entity;		//�߳�����ж����������̻߳����������̣߳�
	double  delay;		//�߳��ӳ�
};

int cnt=1;
typedef HANDLE Semaphore;
Semaphore Empty=NULL;
Semaphore Full=NULL;
CRITICAL_SECTION cs_mutex;
clock_t start, finish;


struct Buffer
{
	int buffer[BUF_SIZE];	//������
	int head;				//ͷָ�룬ָ����һ��д�뻺������λ��
	int tail;				//βָ�룬ָ����һ�δӻ���������λ��
}buf;

void printTime()
{
	finish = clock();
	printf("%.1fs:\t", difftime(finish,start)/1000);
}

void InitBuffer()			//��������ʼ��
{
	memset(buf.buffer, 0, BUF_SIZE);
	buf.head = buf.tail = 0;
}

void do_fill()				//�򻺳�����д��
{
	buf.buffer[buf.head] = cnt++;
	buf.head = (buf.head + 1) % BUF_SIZE;
}

int do_get()				//�ӻ������ж���
{
	int tmp = buf.buffer[buf.tail];
	buf.tail = (buf.tail + 1) % BUF_SIZE;
	return tmp;
}

void ProducerThread(void *p)	//�������߳�
{
	int m_serial= ((ThreadInfo*)(p))->serial;
	double m_delay = (DWORD)(((ThreadInfo*)(p))->delay * INTE_PER_SEC);
	Sleep(m_delay);

	printTime();
	printf("�������߳�%d����.\n\n", m_serial);

	WaitForSingleObject(Empty, -1);				//P(empty)
	EnterCriticalSection(&cs_mutex);			//P(mutex)

	printTime();
	printf("�������߳�%d�򻺳�����������%d.\n\n", m_serial, cnt);
	do_fill();

	LeaveCriticalSection(&cs_mutex);			//V(mutex)
	ReleaseSemaphore(Full, 1, NULL);			//V(full)
}

void ConsumerThread(void* p)	//�������߳�
{
	int m_serial = ((ThreadInfo*)(p))->serial;
	double m_delay = (DWORD)(((ThreadInfo*)(p))->delay * INTE_PER_SEC);
	Sleep(m_delay);

	printTime();
	printf("�������߳�%d����.\n\n", m_serial);

	WaitForSingleObject(Full, -1);				//P(full)
	EnterCriticalSection(&cs_mutex);			//P(mutex)

	int num = do_get();
	printTime();
	printf("�������߳�%d�ӻ�����ȡ������%d.\n\n", m_serial, num);

	LeaveCriticalSection(&cs_mutex);			//V(mutex)
	ReleaseSemaphore(Empty, 1, NULL);			//V(empty)

}

int main()
{
	InitializeCriticalSection(&cs_mutex);
	Empty = CreateSemaphore(NULL, BUF_SIZE, BUF_SIZE, NULL);
	Full = CreateSemaphore(NULL, 0, BUF_SIZE, NULL);

	DWORD n_thread = 0;
	DWORD thread_ID;
	
	HANDLE h_Thread[MAX_THREAD_NUM];
	ThreadInfo thread_info[MAX_THREAD_NUM];

	ifstream fin;
	fin.open("data.txt");
	while (fin)
	{
		fin >> thread_info[n_thread].serial;
		fin >> thread_info[n_thread].entity;
		fin	>> thread_info[n_thread++].delay;
		fin.get();
	}

	start = clock();
	for (int i = 0; i < (int)n_thread; i++)
	{
		if (thread_info[i].entity == PRODUCER)	//�����������߳�
			h_Thread[i]=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(ProducerThread),
										&thread_info[i],0,&thread_ID);
		else									//�����������߳�
			h_Thread[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)(ConsumerThread),
				&thread_info[i], 0, &thread_ID);
	}
	DWORD dw=WaitForMultipleObjects(n_thread, h_Thread, TRUE, (int)(thread_info[n_thread - 1].delay * 1000) +TIMEOUT);
	printTime();
	if (dw == WAIT_TIMEOUT)
		printf("��ʱ�����е������ߺ��������߳�ǿ�ƽ���.\n");
	else
		printf("���е������ߺ��������߳���������.\n");
}