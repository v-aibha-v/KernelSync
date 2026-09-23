#include<iostream>
#include<thread>
using namespace std;
bool flag [2]={false,false};
int turn=0;
void rec(int i){
    int j=1-i;
    for(int k=0;k<10;k++){
        flag[i]=true;//start
        turn=j;
        while(flag[j] and turn ==j ) ; 
         cout<<i<<"is in critical section"<<endl;
        flag[i]=false;//end
        cout<<i<<"is in remainder section"<<endl;
    }
}
int main(){
    thread t1(rec,0);
    thread t2(rec,1);
    t1.join();t2.join();
}