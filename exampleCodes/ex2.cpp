#include<vector>
#include<iostream>
using namespace std;

int main() {
    vector<int> v(3); //宣告一個容量為3的vector
    v[0]=2; //v[0]是第1個元素
    v[1]=7;
    v[2]=9;
    v.insert(v.begin(),8);//在最前面插入新元素。
    v.insert(v.begin()+2,1);//在迭代器中第二個元素前插入新元素
    v.insert(v.end(),3);//在向量末尾追加新元素。

    v.insert(v.end(),4,1);//在尾部插入4個1

    int a[] = {1,2,3,4};
    v.insert(v.end(),a[1],a[3]);//在尾部插入a[1]個a[3]，也就是2個4

    vector<int>::iterator it; //使用iterator存取
    for(it=v.begin(); it!=v.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;

    v.erase(v.begin()+2); //刪除第3個元素
    for(auto e : v)
        cout<<e<<" ";
    cout<<endl;

    v.erase(v.begin()+5,v.begin()+9); //刪除區間5~8

    for(auto e : v)
        cout<<e<<" ";
    cout<<endl;
}
/*output :
    8 2 1 7 9 3 1 1 1 1 4 4
    8 2 7 9 3 1 1 1 1 4 4
    8 2 7 9 3 4 4*/


