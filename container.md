---
description: 容器
---

# 🥗Container

這裡簡單介紹幾個較常用到的容器，包括 : vector, deque, set, map, list, queue, stack。

## vector

Vector 可以看成是一個動態陣列 🎄，宣告時可不指定大小，需要時再追加元素😉，而且可以在中間插入\(insert\)、刪除\(erase\)元素。

#### 用起來跟陣列很像，常用功能有 :

* push\_back : 把一個值加到尾巴
* pop\_back : 把尾巴的值移除掉
* size : 得到目前長度
* \[\] : 得到某一個位置的值
* insert\( vec.begin\(\) + i, a\) : 在第i+1個元素前面插入a
* erase\( vec.begin\(\) + i , vec.begin\(\) + j \)  //刪除區間 i ~ j-1

#### 範例 :

{% code title="ex1.cpp" %}
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec;    // 宣告一個裝 int 的 vector
                        // 現在 vec 是空的
    vec.push_back(10);
    vec.push_back(20);  // 經過三次 push_back
    vec.push_back(30);  // vec 是 [10, 20, 30]

    int length = vec.size();        // length = 3
    for(int i=0 ; i<length ; i++){
        cout << vec[i] << endl;     // 輸出 10, 20, 30
    }

    vec.pop_back();     // 移除 30

    for(int i=0 ; i<vec.size() ; i++){  // vec.size() = 3
        cout << vec[i] << endl;         // 輸出 10, 20
    }
}

```
{% endcode %}

{% code title="ex2.cpp" %}
```cpp
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int> v(3);
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
    for(it=v.begin(); it!=v.end();it++)
    {
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
/*
output : 
    8 2 1 7 9 3 1 1 1 1 4 4
    8 2 7 9 3 1 1 1 1 4 4
    8 2 7 9 3 4 4
*/
```
{% endcode %}



