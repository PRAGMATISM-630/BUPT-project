#include <assert.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_THREAD_NUM 100	    //最大线程数
#define BUF_SIZE 64		    //缓冲区大小

//线程信息结构
typedef struct 
{
    int  tid;		            //线程序号
    int  delay;		            //线程延迟
}ThreadInfo;

int cnt = 1;                    //数字序号
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;   //互斥锁
sem_t empty;                    //信号量empty
sem_t full;                     //信号量full
time_t start_time;              //开始时间

typedef struct
{
    int buffer[BUF_SIZE];	    //缓冲区
    int head;				    //头指针，指向下一次写入缓冲区的位置
    int tail;				    //尾指针，指向下一次从缓冲区读的位置
}Buffer;
Buffer buf;

void InitBuffer()			    //缓冲区初始化
{
    memset(buf.buffer, 0, BUF_SIZE);
    buf.head = buf.tail = 0;
}

void do_fill()				    //向缓冲区中写数
{
    buf.buffer[buf.head] = cnt++;
    buf.head = (buf.head + 1) % BUF_SIZE;
}

int do_get()				    //从缓冲区中读数
{
    int tmp = buf.buffer[buf.tail];
    buf.tail = (buf.tail + 1) % BUF_SIZE;
    return tmp;
}

void PrintTime()
{
    printf("%ds:\t",(int)difftime(time(NULL), start_time));
}

void ProducerThread(void* p)    //生产者线程
{
    ThreadInfo thread = *(ThreadInfo*)p;
    sleep(thread.delay);
    PrintTime();
    printf("Producer thread %d starts.\n\n",thread.tid);

    sem_wait(&empty);               //P(empty)
    pthread_mutex_lock(&mutex);     //P(mutex)

    PrintTime();
    printf("Producer thread %d puts number %d into buffer.\n\n",thread.tid, cnt);
    do_fill();                      //向缓冲区写数
    
    pthread_mutex_unlock(&mutex);   //V(mutex)
    sem_post(&full);                //V(full)
}


void ConsumerThread(void* p)        //消费者线程
{
    ThreadInfo thread = *(ThreadInfo*)p;
    sleep(thread.delay);
    PrintTime();
    printf("Consumer thread %d starts.\n\n",thread.tid);

    sem_wait(&full);                //P(full)
    pthread_mutex_lock(&mutex);     //P(mutex)

    int num = do_get();             //从缓冲区取数
    PrintTime();
    printf("Consumer thread %d gets number %d from buffer.\n\n",thread.tid, num);

    pthread_mutex_unlock(&mutex);   //V(mutex)
    sem_post(&empty);               //V(empty)
}

int main() 
{
    pthread_t tid[MAX_THREAD_NUM];
    ThreadInfo thread[MAX_THREAD_NUM];   

    // 初始化信号量
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

    // 销毁信号量
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
}
