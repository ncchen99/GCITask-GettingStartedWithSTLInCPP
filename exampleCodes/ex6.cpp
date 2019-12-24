#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> q;       // 一個空的 queue
    for(int i=0 ; i<5 ; i++){
        q.push(i * 10);
    }                   // [0, 10, 20, 30, 40]

    while(q.size() != 0){
        cout << q.front() << endl;
        q.pop();
    }                   // 依序輸出 0 10 20 30 40
}
