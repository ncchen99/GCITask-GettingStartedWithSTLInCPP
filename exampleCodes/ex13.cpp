#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main( )
{
    int a[7] = { 3, 2, 5, 1, 2, 1, 8 } ;
    int b[4] = { 1, 7, 4, 9 } ;
    vector<int> v1(a,a+7) ;
    vector<int> v2(b,b+4) ;
    vector<int> v3(v1.size() + v2.size()) ;
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(), v3.begin());
    for (int i=0 ; i<v3.size() ; i++ )
        cout << v3[i] << " " ;
    cout << endl;
    // output : 1 3 2 5 1 2 1 7 4 8 9
    return 0;
}
