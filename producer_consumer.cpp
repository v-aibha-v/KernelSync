// producer consumer
#include <iostream>
#include <thread>
#include <semaphore.h>
using namespace std;
int in = 0, out = 0;
const int SIZE = 5;
int buffer[SIZE];
sem_t emptyslot, full, mutex;
void producer()
{
  for (int i = 0; i < 10; i++)
  {
    sem_wait(&emptyslot);
    sem_wait(&mutex);
    cout << i << "item is produced" << endl;
    buffer[in] = i;
    in = (in + 1) % SIZE;
    sem_post(&mutex);
    sem_post(&full);
  }
}
void consumer()
{
  for (int i = 0; i < 10; i++)
  {
    sem_wait(&full);
    sem_wait(&mutex);
    cout << buffer[out] << "item is consumed" << endl;
    out = (out + 1) % SIZE;
    sem_post(&mutex);
    sem_post(&emptyslot);
  }
}
int main()
{
  sem_init(&emptyslot, 0, SIZE);
  sem_init(&full, 0, 0);
  sem_init(&mutex, 0, 1);
  thread t1(producer);
  thread t2(consumer);
  t1.join();
  t2.join();
}
