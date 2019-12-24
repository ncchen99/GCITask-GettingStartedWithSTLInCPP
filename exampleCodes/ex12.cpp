#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
int main( )
{
    int a[7] = { 1, 3, 2, 5, 1, 2, 1};
    vector<int> v(a,a+7) ;
    vector<int>::iterator it ;
    list<int> L ;
    L.push_back(5);
    L.push_back(1);
    L.push_back(2);
    it = search(v.begin(), v.end(), L.begin(), L.end());
    if (it != v.end()) //¦³§ä¨ì
        cout << *it << " " << *(it+1) << " " << *(it+2) << endl ;
    // output : 5 1 2
    return 0;
}
