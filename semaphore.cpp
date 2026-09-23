##include<iostream>
#include<semaphore.h>
#include<thread>
using namespace std;
sem_t s;
void rec(int i){
    sem_wait(&s);
    cout<<i<<"is in critical section"<<endl;
    cout<<i<<"is begin executing"<<endl;
    cout<<i<<"is successfully executed"<<endl;
    sem_post(&s);
}
int main(){
    sem_init(&s,0,1);
    thread t1(rec,1);
    thread t2(rec,2);
    t1.join();t2.join();
}