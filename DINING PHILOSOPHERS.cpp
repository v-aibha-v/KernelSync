#include<iostream>
#include<thread>
#include<semaphore.h>
using namespace std;
sem_t forkSem[5],room;
void rec(int i){
    for(int k=0;k<2;k++){
        cout<<i<<" is thinking"<<endl;
        sem_wait(&room);
        sem_wait(&forkSem[i]);
        sem_wait(&forkSem[(i+1)%5]);
        cout<<i<<" is eating"<<endl;
        sem_post(&forkSem[(i+1)%5]);
        sem_post(&forkSem[i]);
        sem_post(&room);
    }
}
int main(){
    for(int i=0;i<5;i++) sem_init(&forkSem[i],0,1);
    sem_init(&room,0,4);
    thread t[5];
    for(int i=0;i<5;i++) t[i]=thread(rec,i);
    for(int i=0;i<5;i++)  t[i].join();
    for(int i=0;i<5;i++) sem_destroy(&forkSem[i]);
    sem_destroy(&room);
}