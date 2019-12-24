#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int a[7] = { 1, 3, 2, 4, 1, 2, 1};
    vector<int> v(a,a+7);
    int count_of_1;
    count_of_1 = count(v.begin(), v.end(), 1);
    cout << "count of 1 = " <<count_of_1<<endl;
    // output : count of 1 = 3
    return 0;
}
