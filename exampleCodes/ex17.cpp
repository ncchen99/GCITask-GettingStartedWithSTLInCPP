#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[1001]={1,1,2,3,4,5,7,8,10,15};
    sort(a,a+10);
    int l=lower_bound(a,a+10,5)-a;
    //皚い材┪单琩高计(5)
	int r=upper_bound(a,a+10,5)-a;
	//皚い材琩高计
    cout<<l<<" "<<a[l]<<endl;
    cout<<r<<" "<<a[r];
    return 0;
}
// output : 5 5
//          6 7
