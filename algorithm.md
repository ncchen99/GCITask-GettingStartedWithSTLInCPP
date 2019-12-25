---
description: 演算法
---

# 🎺Algorithm

在STL中除了提供容器\(類別樣板\), 尚提供演算法\(函式 樣板\)以供操作之資料 

需 include &lt;algorithm&gt;

常用演算法:

* find 
* count 
* search 
* merge 
* sort 
* for\_each 
* transform
* upper\_bound
* lower\_bound

## find

#### 用法 : 

find\(first, last, val\) 

* \[first\]: iterator  
* \[last\]: iterator 
* \[val\]: target value type 
* \[回傳值\]: iterator 

針對某個container做搜尋,區間由first及last這兩個iterator指定,目標值為val,找到後回傳其所在元素指標\(也是以iterator表示\)，也就是尋找元素在容器中第一個出現的位子。

#### 陣列搜尋

{% code title="ex9.cpp" %}
```cpp
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
```
{% endcode %}

#### vector搜尋

{% code title="ex10.cpp" %}
```cpp
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
```
{% endcode %}

## count

count\(first, last, val\) 

* \[first\]: iterator 
* \[last\]: iterator 
* \[val\]: target value type 
* \[回傳值\]: int 

針對某個container做搜尋,區間由first及last這兩個iterator指定,目標值為val,回傳container中元素值為val的個數，也就是統計在容器中共有幾個「指定的元素」。

{% code title="ex11.cpp" %}
```cpp
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
```
{% endcode %}

## search

search\(s\_first , s\_last , t\_first , t\_last\)

* \[s\_first\] \[t\_first\] : iterator 
* \[s\_last\] \[t\_last\] : iterator 
* \[回傳值\] : iterator 

找尋某一資料序列是否出現在另一個容器中。

#### 範例 : list容器中做搜尋

{% code title="ex12.cpp" %}
```cpp
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
    if (it != v.end()) //有找到
        cout << *it << " " << *(it+1) << " " << *(it+2) << endl ;
    // output : 5 1 2
    return 0;
}
```
{% endcode %}

## merge

merge\(s1\_first, s1\_last, s2\_first, s2\_last, t\_first\)

* \[s1\_first\] \[s2\_first\]: iterator
* \[s1\_last\] \[s2\_last\]: iterator 
* \[t\_first\] : iterator
* \[回傳值\] : iterator 

合併s1與s2兩資料於t

{% code title="ex13.cpp" %}
```cpp
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
```
{% endcode %}

## sort 

 sort\(first, last\) 

* sort\(first, last, f\)
* \[first\]: iterator 
* \[last\]: iterator
* \[f\]: 函式 \(可有可無\)
* \[回傳值\]: void

資料排序 \(預設由小到大\)

{% code title="ex14.cpp" %}
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool mygreater(int x, int y) //←改成結構試試看
{
    return x>y;
}
int main()
{
    int a[7] = { 8, 1, 3, 2, 5, 1, 4};
    vector<int> v(a,a+7);
    vector<int>::iterator it ;
    sort(v.begin(), v.end()) ; //由小排到大
    for ( it = v.begin(); it != v.end() ; it++)
        cout << *it <<" ";
    cout << endl;
    // output : 1 1 2 3 4 5 8
    sort(v.begin(), v.end(), mygreater); //mygreater 由大排到小
    for ( it = v.begin( ); it != v.end() ; it++)
        cout << *it <<" ";
    cout << endl;
    // output : 8 5 4 3 2 1 1
    return 0;
}
```
{% endcode %}

## for\_each 

for\_each\(first, last, f\) 

* \[first\] : iterator
* \[last\] : iterator 
* \[f\] : 函式 
* \[回傳值\] : 函數物件指標

 對container中從first 所指的元素起到last為止,其間每一個元素做某個動作\(由函數f指定\)

{% code title="ex15.cpp" %}
```cpp
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
```
{% endcode %}

## transform 

transform\(first, last, output, f\) 

* \[first\] : iterator 
* \[last\] : iterator 
* \[output\] : container
* \[f\] : 函式
* \[回傳值\] : 函數物件指標 

同for\_each,但會把結果放在output容器中

{% code title="ex16.cpp" %}
```cpp
#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
void print(int &x) {
    cout << x << " ";
}
int add(int x) {
    return x+5;
}
int main() {
    list<int> L;
    vector<int> v(3);
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    transform(L.begin(), L.end(), v.begin(), add);
    for_each(L.begin(), L.end(), print);
    cout << endl;
    for_each(v.begin(), v.end(), print);
    cout << endl;
    return 0;
}
// output : 10 20 30
//          15 25 35
```
{% endcode %}

## upper\_bound & lower\_bound

首先，使用的前提是排好序的非遞減陣列。lower\_bound\( \)和upper\_bound\( \)都是利用二分查詢的方法在一個排好序的陣列、容器中進行查詢的。

lower\_bound\( begin,end,num\)：從陣列的begin位置到end-1位置二分查詢第一個大於或等於num的數字，找到返回該數字的地址，不存在則返回end。通過返回的地址減去起始地址begin,得到找到數字在陣列中的下標。

upper\_bound\( begin,end,num\)：從陣列的begin位置到end-1位置二分查詢第一個大於num的數字，找到返回該數字的地址，不存在則返回end。通過返回的地址減去起始地址begin,得到找到數字在陣列中的下標。

{% code title="ex17.cpp" %}
```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[1001]={1,1,2,3,4,5,7,8,10,15};
    sort(a,a+10);
    int l=lower_bound(a,a+10,5)-a;    
    //返回陣列中第一個大於或等於查詢數(5)的值
	int r=upper_bound(a,a+10,5)-a;    
	//返回陣列中第一個大於查詢數的值
    cout<<l<<" "<<a[l]<<endl;
    cout<<r<<" "<<a[r];
    return 0;
}
// output : 5 5
//          6 7
```
{% endcode %}



