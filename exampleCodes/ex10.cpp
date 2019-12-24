#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main( )
{
    list<int> L;
    list<int>::iterator it;
    L.push_back(10) ;
    L.push_back(20);
    L.push_back(30);
    it = find(L.begin( ), L.end( ), 30);
    if ( it == L.end( ))
        cout << "data not found\n";
    else
        cout << *it << endl;
    //output : 30
    return 0;
}
