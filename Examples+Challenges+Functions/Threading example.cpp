#include<iostream>
#include<pthread.h>
typedef void* pass;
using namespace std;
long long sum[4];

pass thread_fn(pass arg)
{
    long id = long(arg);
    int start = id * 250000;

    for(int i=0;i<250000;i++)
        sum[id]+=(start+i);
}

int main()
{
    pthread_t t1,t2,t3,t4;

    pthread_create(&t1,NULL,thread_fn,pass(0));
    pthread_create(&t2,NULL,thread_fn,pass(1));
    pthread_create(&t3,NULL,thread_fn,pass(2));
    pthread_create(&t4,NULL,thread_fn,pass(3));
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    cout<<"Sum of first 1 million Number is : "<<sum[0]+sum[1]+sum[2]+sum[3]/*+1000000*/;
    return 0;
}
