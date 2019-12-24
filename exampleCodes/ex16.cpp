#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
void print(int &x) {
    cout << x << " ";
}
int add(int x) {
    return x+5;
}
int main() {
    list<int> L;
    vector<int> v(3);
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    transform(L.begin(), L.end(), v.begin(), add);
    for_each(L.begin(), L.end(), print);
    cout << endl;
    for_each(v.begin(), v.end(), print);
    cout << endl;
    return 0;
}
// output : 10 20 30
//          15 25 35
