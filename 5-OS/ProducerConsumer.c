#include <assert.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_THREAD_NUM 100	    //����߳���
#define BUF_SIZE 64		    //��������С

//�߳���Ϣ�ṹ
typedef struct 
{
    int  tid;		            //�߳����
    int  delay;		            //�߳��ӳ�
}ThreadInfo;

int cnt = 1;                    //�������
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;   //������
sem_t empty;                    //�ź���empty
sem_t full;                     //�ź���full
time_t start_time;              //��ʼʱ��

typedef struct
{
    int buffer[BUF_SIZE];	    //������
    int head;				    //ͷָ�룬ָ����һ��д�뻺������λ��
    int tail;				    //βָ�룬ָ����һ�δӻ���������λ��
}Buffer;
Buffer buf;

void InitBuffer()			    //��������ʼ��
{
    memset(buf.buffer, 0, BUF_SIZE);
    buf.head = buf.tail = 0;
}

void do_fill()				    //�򻺳�����д��
{
    buf.buffer[buf.head] = cnt++;
    buf.head = (buf.head + 1) % BUF_SIZE;
}

int do_get()				    //�ӻ������ж���
{
    int tmp = buf.buffer[buf.tail];
    buf.tail = (buf.tail + 1) % BUF_SIZE;
    return tmp;
}

void PrintTime()
{
    printf("%ds:\t",(int)difftime(time(NULL), start_time));
}

void ProducerThread(void* p)    //�������߳�
{
    ThreadInfo thread = *(ThreadInfo*)p;
    sleep(thread.delay);
    PrintTime();
    printf("Producer thread %d starts.\n\n",thread.tid);

    sem_wait(&empty);               //P(empty)
    pthread_mutex_lock(&mutex);     //P(mutex)

    PrintTime();
    printf("Producer thread %d puts number %d into buffer.\n\n",thread.tid, cnt);
    do_fill();                      //�򻺳���д��
    
    pthread_mutex_unlock(&mutex);   //V(mutex)
    sem_post(&full);                //V(full)
}


void ConsumerThread(void* p)        //�������߳�
{
    ThreadInfo thread = *(ThreadInfo*)p;
    sleep(thread.delay);
    PrintTime();
    printf("Consumer thread %d starts.\n\n",thread.tid);

    sem_wait(&full);                //P(full)
    pthread_mutex_lock(&mutex);     //P(mutex)

    int num = do_get();             //�ӻ�����ȡ��
    PrintTime();
    printf("Consumer thread %d gets number %d from buffer.\n\n",thread.tid, num);

    pthread_mutex_unlock(&mutex);   //V(mutex)
    sem_post(&empty);               //V(empty)
}

int main() 
{
    pthread_t tid[MAX_THREAD_NUM];
    ThreadInfo thread[MAX_THREAD_NUM];   

    // ��ʼ���ź���
    sem_init(&empty, 0, BUF_SIZE);
    sem_init(&full, 0, 0);
    
    start_time = time(NULL);

    int tidEnd = 0;
    int arg_tid;
    int arg_delay;
    char arg_type;

    FILE* fp;
    fp = fopen("data.txt", "r");
    while (fscanf(fp,"%d %c %d", &arg_tid, &arg_type, &arg_delay) == 3) 
    {
        assert(tidEnd < MAX_THREAD_NUM);
        if (arg_type == 'P') 
        {
            thread[tidEnd].tid = arg_tid;
            thread[tidEnd].delay = arg_delay;
            pthread_create(tid + tidEnd, NULL, ProducerThread, thread + tidEnd);
        }
        else 
        {
            thread[tidEnd].tid = arg_tid;
            thread[tidEnd].delay = arg_delay;
            pthread_create(tid + tidEnd, NULL, ConsumerThread, thread + tidEnd);
        }
        ++tidEnd;
    }
   
    for (int i = 0; i != tidEnd; ++i) 
        pthread_join(tid[i], NULL);

    // �����ź���
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
}
