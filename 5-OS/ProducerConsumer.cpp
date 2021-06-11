#include<Windows.h>
#include<fstream>
#include<stdlib.h>
#include<time.h>

using namespace std;

#define PRODUCER 'P'		//生产者
#define CONSUMER 'C'		//消费者
#define INTE_PER_SEC 1000	//每秒时钟中断数目
#define MAX_THREAD_NUM 64	//最大线程数
#define BUF_SIZE 2			//缓冲区大小

//超时时限60000ms(从最后一个线程创建开始，如果超过时间60s，
//仍然有消费者线程取不到数或生产者线程放不了数，那么结束线程
#define TIMEOUT 20000		

struct ThreadInfo
{
	int  serial;		//线程序号
	char  entity;		//线程类别（判断是生产者线程还是消费者线程）
	double  delay;		//线程延迟
};

int cnt=1;
typedef HANDLE Semaphore;
Semaphore Empty=NULL;
Semaphore Full=NULL;
CRITICAL_SECTION cs_mutex;
clock_t start, finish;


struct Buffer
{
	int buffer[BUF_SIZE];	//缓冲区
	int head;				//头指针，指向下一次写入缓冲区的位置
	int tail;				//尾指针，指向下一次从缓冲区读的位置
}buf;

void printTime()
{
	finish = clock();
	printf("%.1fs:\t", difftime(finish,start)/1000);
}

void InitBuffer()			//缓冲区初始化
{
	memset(buf.buffer, 0, BUF_SIZE);
	buf.head = buf.tail = 0;
}

void do_fill()				//向缓冲区中写数
{
	buf.buffer[buf.head] = cnt++;
	buf.head = (buf.head + 1) % BUF_SIZE;
}

int do_get()				//从缓冲区中读数
{
	int tmp = buf.buffer[buf.tail];
	buf.tail = (buf.tail + 1) % BUF_SIZE;
	return tmp;
}

void ProducerThread(void *p)	//生产者线程
{
	int m_serial= ((ThreadInfo*)(p))->serial;
	double m_delay = (DWORD)(((ThreadInfo*)(p))->delay * INTE_PER_SEC);
	Sleep(m_delay);

	printTime();
	printf("生产者线程%d启动.\n\n", m_serial);

	WaitForSingleObject(Empty, -1);				//P(empty)
	EnterCriticalSection(&cs_mutex);			//P(mutex)

	printTime();
	printf("生产者线程%d向缓冲区放入数字%d.\n\n", m_serial, cnt);
	do_fill();

	LeaveCriticalSection(&cs_mutex);			//V(mutex)
	ReleaseSemaphore(Full, 1, NULL);			//V(full)
}

void ConsumerThread(void* p)	//消费者线程
{
	int m_serial = ((ThreadInfo*)(p))->serial;
	double m_delay = (DWORD)(((ThreadInfo*)(p))->delay * INTE_PER_SEC);
	Sleep(m_delay);

	printTime();
	printf("消费者线程%d启动.\n\n", m_serial);

	WaitForSingleObject(Full, -1);				//P(full)
	EnterCriticalSection(&cs_mutex);			//P(mutex)

	int num = do_get();
	printTime();
	printf("消费者线程%d从缓冲区取得数字%d.\n\n", m_serial, num);

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
		if (thread_info[i].entity == PRODUCER)	//创建生产者线程
			h_Thread[i]=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(ProducerThread),
										&thread_info[i],0,&thread_ID);
		else									//创建消费者线程
			h_Thread[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)(ConsumerThread),
				&thread_info[i], 0, &thread_ID);
	}
	DWORD dw=WaitForMultipleObjects(n_thread, h_Thread, TRUE, (int)(thread_info[n_thread - 1].delay * 1000) +TIMEOUT);
	printTime();
	if (dw == WAIT_TIMEOUT)
		printf("超时，所有的生产者和消费者线程强制结束.\n");
	else
		printf("所有的生产者和消费者线程正常结束.\n");
}