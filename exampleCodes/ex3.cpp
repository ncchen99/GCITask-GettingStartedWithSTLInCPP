#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> mySet;
    mySet.insert(20);   // mySet = {20}
    mySet.insert(10);   // mySet = {10, 20}
    mySet.insert(30);   // mySet = {10, 20, 30}

    cout << mySet.count(20) << endl;    // 存在 -> 1
    cout << mySet.count(100) << endl;   // 不存在 -> 0

    mySet.erase(20);                    // mySet = {10, 30}
    cout << mySet.count(20) << endl;    // 0
}
