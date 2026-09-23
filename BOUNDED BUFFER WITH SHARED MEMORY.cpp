#include <iostream>
#include <thread>
#include <semaphore.h>
using namespace std;

const int SIZE = 5;

int sharedBuffer[SIZE];
int in = 0, out = 0;

sem_t empty, full, mutex;

void producer()
{

  for (int i = 1; i <= 10; i++)
  {

    sem_wait(&empty);
    sem_wait(&mutex);

    sharedBuffer[in] = i;

    cout << "Producer placed: "
         << i << " in shared memory\n";

    in = (in + 1) % SIZE;

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

    int item = sharedBuffer[out];

    cout << "Consumer received: "
         << item << " from shared memory\n";

    out = (out + 1) % SIZE;

    sem_post(&mutex);
    sem_post(&empty);
  }
}

int main()
{

  sem_init(&empty, 0, SIZE);
  sem_init(&full, 0, 0);
  sem_init(&mutex, 0, 1);

  thread p(producer);
  thread c(consumer);

  p.join();
  c.join();

  return 0;
}