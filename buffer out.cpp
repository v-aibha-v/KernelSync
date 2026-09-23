#include <iostream>
#include <thread>
#include <semaphore.h>
using namespace std;
const int N = 5;
int buffer[N];
int in = 0, out = 0;
sem_t empty, full, mutex;
void producer()
{
  for (int i = 1; i <= 10; i++)
  {
    sem_wait(&empty);
    sem_wait(&mutex);
    buffer[in] = i;
    cout << "Produced " << i << endl;

    in = (in + 1) % N;

    sem_post(&mutex);
    sem_post(&full);
  }
}

void consumer()
{
  for (int i = 1; i <= 10; i++)
  {

    sem_wait(&full);
    sem_wait(&mutex);

    int item = buffer[out];

    cout << "Consumed " << item << endl;

    out = (out + 1) % N;

    sem_post(&mutex);
    sem_post(&empty);
  }
}

int main()
{
  sem_init(&empty, 0, N);
  sem_init(&full, 0, 0);
  sem_init(&mutex, 0, 1);
  thread p(producer);
  thread c(consumer);
  p.join();
  c.join();
  return 0;
}