#include <iostream>
#include <thread>
#include <semaphore.h>
using namespace std;
sem_t mutex, rw;
int count = 0, value = 0;
void reader(int id) {
    sem_wait(&mutex);
    count++;
    if (count == 1) sem_wait(&rw);
    sem_post(&mutex);
    cout << "Reader " << id << " reads " << value << endl;
    sem_wait(&mutex);
    count--;
    if (count == 0) sem_post(&rw);
    sem_post(&mutex);
}
void writer(int id) {
    sem_wait(&rw);
    value++;
    cout << "Writer " << id << " writes " << value << endl;
    sem_post(&rw);
}
int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&rw, 0, 1);
    thread r1(reader, 1), r2(reader, 2);
    thread w(writer, 1);
    r1.join();
    r2.join();
    w.join();
    sem_destroy(&mutex);
    sem_destroy(&rw);
}