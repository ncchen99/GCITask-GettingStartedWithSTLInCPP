#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
void print(int &x)
{
    cout << x << " ";
}
void add(int &x)
{
    x = x+5;
}
int main( )
{
    list<int> L ;
    L.push_back(10);
    L.push_back(20) ;
    L.push_back(30) ;
    for_each(L.begin( ), L.end( ), print) ;
    cout << endl;
    for_each(L.begin( ), L.end( ), add) ;
    for_each(L.begin( ), L.end( ), print) ;
    cout << endl;
    return 0;
}
// output : 10 20 30
//          15 25 35
