//#include<iostream>
//#include<list>
//
//using namespace std;
//template <class T>
//
//void Print(list<T>& l){
//  list<int>::iterator it=l.begin();
//  while(it!=l.end()){
//    cout<<*it<<" ";
//    ++it;
//  }
//  cout<<endl;
//}
//
//int main(){
//  list<int> l;
//  l.push_back(1);
//  l.push_front(2);
//  Print(l);
//
//
//  list<int> l1(10,2);
//
//  Print(l1);
//  list<int> l2(l1.begin(),l1.end());
//  Print(l2);
//
//  list<int> l3(l2);
//  Print(l3);
//
//  cout<<"l.rbegin():"<<*l.rbegin()<<endl;
//  cout<<"l.rend():"<<*l.rend() <<endl; 
//  //返回的是最后一个元素下一个位置的reverse_itreator
//  //既begin的位置
//  cout<<"l.begin():"<<*l.begin()<<endl;
//  cout<<"l.end():"<<*l.end()<<endl;
//  cout<<"l.cbegin():"<<*l.cbegin()<<endl;
//  cout<<"l.cend():"<<*l.cend()<<endl;
//  cout<<"l.crbegin():"<<*l.crbegin()<<endl;
//  cout<<"l.crend():"<<*l.crend()<<endl;
//  return 0;
//}




//#include <iostream>
//
//#include <list>
//
//using namespace std;
//int main()
//{
//  int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0  };
//  list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//  // 使用正向迭代器正向list中的元素
//  for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
//    cout << *it << " ";
//  cout << endl;
//  // 使用反向迭代器逆向打印list中的元素
//  for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
//    cout << *it << " ";
//  cout << endl;
//  // cosnt的正向迭代器
//  auto cit = l.cbegin();
//  cout << typeid(cit).name() << endl;
//  //*cit = 10; 此行代码编译失败，因为cit为 const_iterator类型的迭代器
//  return 0; 
//}



//#include <iostream>
//#include <list>
//
//using namespace std;
//int main()
//{
//  int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0  };
//  list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//
//  // 打印list中有效节点的个数
//  cout << l.size() << endl;
//  // 检测list是否为空
//  if (l.empty())
//    cout << "空的list" << endl;
//  else
//  {
//    for (const auto& e : l)
//      cout << e << " ";
//    cout << endl;
//  }
//  return 0; 
//}
//


//#include <iostream>
//#include <list>
//
//using namespace std;
//
//int main()
//{
//  int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0  };
//  list<int> l1(array, array + sizeof(array) / sizeof(array[0]));
//  for (auto& e : l1)
//    cout << e << " ";
//  cout << endl;
//  // 将list中第一个节点与最后一个节点中的值改为10
//  l1.front() = 10;
//  l1.back() = 10;
//  for (auto& e : l1)
//    cout << e << " ";
//  cout << endl;
//  const list<int> l2(array, array + sizeof(array) / sizeof(array[0]));
//  //int& a = l2.front(); 因为l2是const类型的list对象，因此其front()为const 引用类型
//  const int& ca = l2.front();
//  return 0; 
//
//}




//#include<iostream>
//#include <list>
//#include<vector>
//
//using namespace std;
//
//void PrintList(list<int>& l) {
//   for (auto& e : l)
//      cout << e << " ";
//     cout << endl; 
//}
////=========================================================================================
//// push_back/pop_back/push_front/pop_front
//void TestList1()
//{
//  int array[] = { 1, 2, 3  };
//  list<int> L(array, array+sizeof(array)/sizeof(array[0]));
//  // 在list的尾部插入4，头部插入0
//  L.push_back(4);
//  L.push_front(0);
//  PrintList(L);
//  // 删除list尾部节点和头部节点
//  L.pop_back();
//  L.pop_front();
//  PrintList(L);
//}
////=========================================================================================
//// emplace_back / emplace_front / emplace
//class Date
//{
//  public:
//    Date(int year = 1900, int month = 1, int day = 1)
//      : _year(year)
//        , _month(month)
//        , _day(day)
//  {
//    cout << "Date(int, int, int):" << this << endl;
//  }
//    Date(const Date& d)
//      : _year(d._year)
//        , _month(d._month)
//        , _day(d._day)
//  {
//    cout << "Date(const Date&):" << this << endl;
//  }
//  private:
//    int _year;
//    int _month;
//    int _day;
//};
//// push_back尾插：先构造好元素，然后将元素拷贝到节点中，插入时先调构造函数，再调拷贝构造函数
//// emplace_back尾插：先构造节点，然后调用构造函数在节点中直接构造对象
//// emplace_back比push_back更高效，少了一次拷贝构造函数的调用
//void TestList2()
//{
//  list<Date> l;
//  Date d(2018, 10, 20);
//  l.push_back(d);
//  l.emplace_back(2018, 10, 21);
//  l.emplace_front(2018, 10, 19);
//}
////=========================================================================================
//// insert /erase 
//void TestList3()
//{
//  int array1[] = { 1, 2, 3  };
//  list<int> L(array1, array1+sizeof(array1)/sizeof(array1[0]));
//  // 获取链表中第二个节点
//  auto pos = ++L.begin();
//  cout << *pos << endl;
//  // 在pos前插入值为4的元素
//  L.insert(pos, 4);
//  PrintList(L);
//  // 在pos前插入5个值为5的元素
//  L.insert(pos, 5, 5);
//  PrintList(L);
//  // 在pos前插入[v.begin(), v.end)区间中的元素
//  vector<int> v{ 7, 8, 9  };
//  L.insert(pos, v.begin(), v.end());
//  PrintList(L);
//  // 删除pos位置上的元素
//  L.erase(pos);
//  PrintList(L);
//  // 删除list中[begin, end)区间中的元素，即删除list中的所有元素
//  L.erase(L.begin(), L.end());
//  PrintList(L);
//}
//// resize/swap/clear
//void TestList4()
//{
//  // 用数组来构造list
//  int array1[] = { 1, 2, 3  };
//  list<int> l1(array1, array1+sizeof(array1)/sizeof(array1[0]));
//  PrintList(l1);
//  // 将l1中元素个数增加到10个，多出的元素用默认值填充
//  // (注意：如果list中放置的是内置类型，默认值为0, 如果list中放置自定义类型元素，调用缺省构造函数)
//  l1.resize(10);
//  PrintList(l1);
//  // 将l1中的元素增加到20个，多出的元素用4来填充
//  l1.resize(20, 4);
//  PrintList(l1);
//  // 将l1中的元素减少到5个
//  l1.resize(5);
//  PrintList(l1);
//  // 用vector中的元素来构造list
//  vector<int> v{ 4, 5, 6  };
//  list<int> l2(v.begin(), v.end());
//  PrintList(l2);
//  // 交换l1和l2中的元素
//  l1.swap(l2);
//  PrintList(l1);
//  PrintList(l2);
//  // 将l2中的元素清空
//  l2.clear();
//  cout<<l2.size()<<endl; 
//}
//  
//
//int main(){
//  TestList1();
//  TestList2();
//  TestList3();
//  TestList4();
//  return 0;
//}



#include<iostream>
#include<list>
#include<vector>

using namespace std;

void TestListIterator1()
{
   int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0  };
   list<int> l(array, array+sizeof(array)/sizeof(array[0]));
   auto it = l.begin();
   cout<<*it<<endl;
   while (it != l.end())
   {
      // erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给其赋
      // 值
    it=l.erase(it); 
    cout<<*it<<" ";
     ++it; 
   }
   cout<<endl;
}
// 改正
void TestListIterator()
{
 int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0  };
 list<int> l(array, array+sizeof(array)/sizeof(array[0]));
 auto it = l.begin();
 while (it != l.end())
 {
  it=l.erase(it); // it = l.erase(it);
  cout<<*it<<" ";
  it++; 
 }
 cout<<endl;
}


void PrintNode(){
 int array[]={0,1,2,3,4,5,6,7,8,9};
 list<int> l(array,array+sizeof(array)/sizeof(array[0]));
 list<int> l5;
 l5=l;
 cout<<"l:";
  auto it5=l.begin();
 while(it5!=l.end()){
   cout<<*it5<<" ";
   it5++;
 }
cout<<endl;

cout<<"l5:";

  auto it6=l.begin();
 while(it6!=l.end()){
   cout<<*it6<<" ";
   it6++;
 }
 cout<<endl;
 auto it=l.begin();
 while(it!=l.end()){
   cout<<*it<<" ";
   it++;
 }
 cout<<endl;
 auto en=l.end();
 cout<<"l.end():"<<*en<<endl;
 cout<<"l.begin()"<<*it<<endl;
 l.insert(l.begin(),19);
 l.insert(l.end(),20);
 auto it1=l.begin();
 while(it1!=l.end()){
   cout<<*it1<<" ";
   it1++;
 }
 cout<<endl;
}
 int main(){
   TestListIterator();
   TestListIterator1();
   PrintNode();
   return 0;
}
 
 

