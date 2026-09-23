#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
using namespace std;
struct Msg {
    long type;
    char text[100];
};
int main() {
    int id = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    pid_t p = fork();
    if (p == 0) {
        Msg m;
        msgrcv(id, &m, sizeof(m.text), 1, 0);
        cout << "Received: " << m.text << endl;
    }
    else {
        Msg m = {1, "Hello from Parent!"};
        msgsnd(id, &m, sizeof(m.text), 0);
        wait(NULL);
        msgctl(id, IPC_RMID, NULL);
    }
    return 0;
}