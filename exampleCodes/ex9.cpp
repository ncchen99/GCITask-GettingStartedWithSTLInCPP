#include<iostream>
#include<algorithm>
using namespace std;
int main( )
{
    int l[7] = { 1, 3, 2, 5, 1, 2, 1 };
    int *it ;
    it = find(&l[0], &l[7], 5);
    if ( it == l+7)
        cout << "data not found\n" ;
    else
        cout << *it << endl;
    // output : 5
    return 0;
}
