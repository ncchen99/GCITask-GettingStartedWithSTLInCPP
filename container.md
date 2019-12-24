---
description: 容器
---

# 🥗Container

這裡簡單介紹幾個較常用到的容器，包括 : vector, set, map, list, queue, stack。

## vector

Vector 可以看成是一個動態陣列 🎄，宣告時可不指定大小，需要時再追加元素😉，而且可以在中間插入\(insert\)、刪除\(erase\)元素。不過要注意在數量很大時，插入和刪除效率會不好的，如果有在最前面增加、刪除元素的需求可以用deque\(雙端佇列\)，效率會比較高喔。

![&#x5F15;&#x7528;&#x81EA;:https://larry850806.github.io/2016/06/06/STL1/](.gitbook/assets/image.png)

#### 用起來跟陣列很像，常用功能有 :

* push\_back : 把一個值加到尾巴
* pop\_back : 把尾巴的值移除掉
* size : 得到目前長度
* \[\] : 得到某一個位置的值
* insert\( vec.begin\(\) + i, a\) : 在第i+1個元素前面插入a
* erase\( vec.begin\(\) + i , vec.begin\(\) + j \)  //刪除區間 i ~ j-1

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

int main() {
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
/*
output :
    8 2 1 7 9 3 1 1 1 1 4 4
    8 2 7 9 3 1 1 1 1 4 4
    8 2 7 9 3 4 4
*/
```
{% endcode %}

## set

Set 就是集合內部資料結構為一顆紅黑樹 \(red-black tree\)，裡面的元素都不會重覆，而且都會由小排到大，不過數量多時效率還是會糟的 !

#### 基本功能有: <a id="&#x57FA;&#x672C;&#x529F;&#x80FD;&#x6709;-2"></a>

* insert\(\) : 把一個數字放進集合
* erase\(\) : 把某個數字從集合中移除
* count\(\) : 檢查某個數是否有在集合中

{% code title="ex3.cpp" %}
```cpp
#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> mySet;
    mySet.insert(20);   // mySet = {20}
    mySet.insert(10);   // mySet = {10, 20}
    mySet.insert(30);   // mySet = {10, 20, 30}

    cout << mySet.count(20) << endl;    // 存在 -> 1
    cout << mySet.count(100) << endl;   // 不存在 -> 0

    mySet.erase(20);                    // mySet = {10, 30}
    cout << mySet.count(20) << endl;    // 0
}
```
{% endcode %}

## map

 它提供搜尋和插入友善的資料結構，並具有一對一 mapping 功能：

* 第一個稱為關鍵字 \(key\)，每個關鍵字只能在 map 中出現一次。
* 第二個稱為該關鍵字的值 \(value\)。

  
Map 的 key-value 對應主要用於資料一對一映射 \(one-to-one\) 的情況，比如一個班級中，每個學生的學號跟他的姓名就存在著一對一映射的關係。

**Map 的特色**

* map 內部資料結構為一顆紅黑樹 \(red-black tree\)，因此：
  * 內部是有排序的資料。
  * 對於搜尋和插入操作友善\( O\(logn\) \)。
* 可以修改 value 值、不能修改 key 值。
* 以模板（泛型）方式實現，可以儲存任意類型的變數，包括使用者自定義的資料型態 。

![&#x5F15;&#x7528;&#x81EA; : https://mropengate.blogspot.com/2015/12/cc-map-stl.html](.gitbook/assets/image%20%283%29.png)

{% code title="ex4.cpp" %}
```cpp
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

    //declaration container and iterator
    map<string, string> mapStudent;
    map<string, string>::iterator iter;
    map<string, string>::reverse_iterator iter_r;

    //insert element
    mapStudent.insert(pair<string, string>("r000", "student_zero"));

    mapStudent["r123"] = "student_first";
    mapStudent["r456"] = "student_second";

    //traversal
    for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
                cout<<iter->first<<" "<<iter->second<<endl;
    for(iter_r = mapStudent.rbegin(); iter_r != mapStudent.rend(); iter_r++)
                cout<<iter_r->first<<" "<<iter_r->second<<endl;

    //find and erase the element
    iter = mapStudent.find("r123");
    mapStudent.erase(iter);

    iter = mapStudent.find("r123");

    if(iter != mapStudent.end())
       cout<<"Find, the value is "<<iter->second<<endl;
    else
       cout<<"Do not Find"<<endl;

    return 0;
}
```
{% endcode %}

