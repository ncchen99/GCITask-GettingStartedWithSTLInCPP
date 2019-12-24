#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> s;

    s.push(10);     //  | 30 |
    s.push(20);     //  | 20 |   疊三個盤子
    s.push(30);     //  |_10_|   10 在最下面

    for(int i=0 ; i<s.size() ; i++){    // s.size() = 3
        cout << s.top() << endl;
        s.pop();
    }                                   // 輸出 30, 20, 10
}
