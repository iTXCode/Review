//#include<iostream>
//#include<vector>
//
//using namespace  std;
//void Print(vector<int> &v1){
//  vector<int>::iterator vt=v1.begin();
//
//  while(vt!=v1.end()){
//    cout<<*vt<<" ";
//    vt++;
//  }
//  cout<<endl;
//}
//
//int main(){
//  vector<int> v;
//  v.push_back(1);
//  v.push_back(2);
//  v.push_back(3);
//  v.pop_back();
//  vector<int>::iterator vit=v.begin();
//  while(vit!=v.end()){
//    cout<<*vit<< " ";
//    vit++;
//  }
//  cout<<endl;
//  auto  cvit=v.rbegin();
//  while(cvit!=v.rend()){
//    cout<<*cvit<<" ";
//    cvit++;
//  }
//  cout<<endl;
//  vector<int>::const_iterator cvt=v.begin();
//  while(cvt!=v.end()){
//    cout<<*cvt<<" ";
//    cvt++;
//  }
//  cout<<endl;
//  cout<<"swap before:"<<endl;
//  vector<int> v1(3,2);
//  cout<<"v1:";
//  Print(v1);
//  vector<int> v2(2,3);
//  cout<<"v2:";
//  Print(v2);
//  cout<<endl;
//  swap(v1,v2);
//  cout<<"swap after:"<<endl;
//  cout<<"v1:";
//  Print(v1);
//  cout<<"v2:";
//  Print(v2);
//
//  return 0;
//}
//

//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//
//int main(){
//  //vector::capacity()的使用
//  vector<int> v3(3);
//  vector<int> v(10,5);
//  cout<<v.capacity()<<endl;
//  
//  //vector::reserve()的使用
//  v.reserve(20);
//  cout<<v.capacity()<<endl;
//  
//  vector<int>::iterator vt=v.begin();
//  while(vt!=v.end()){
//    cout<<*vt<<" ";
//    vt++;
//  }
//  cout<<endl;
//
//  v.resize(30,1);
//  vector<int>::iterator vt1=v.begin();
//  while(vt1!=v.end()){
//    cout<<*vt1<<" ";
//    vt1++;
//  }
//  cout<<endl;
//  return 0;
//}
//



//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//
//using namespace  std;
//
//template <class T>
//void Print(vector<T>& v){
//
//  auto it=v.begin();
//  while(it!=v.end()){
//    cout<<*it<<" ";
//    it++;
//  }    
//  cout<<endl;
//}
//
//int main(){
//  std::vector<int> v;
//  std::cout<<v.size()<<std::endl;
//  std::cout<<v.capacity()<<std::endl;
//  v.insert(v.begin(),3);
//  std::cout<<v[0]<<std::endl;
//
//  std:: vector<std::string> v1(2,"bit");
//  std::cout<<v1[0]<<std::endl;
//
//  v.push_back(1);
//  v.push_back(2);
//  v.push_back(3);
//  v.push_back(4);
//  vector<int>::iterator pos=find(v.begin(),v.end(),3);
//  v.insert(pos,520);
//  cout<<*pos<<endl;
//
//  pos=v.erase(pos);
//  cout<<"*pos:"<<*pos<<endl;
//  Print(v);
//  return 0;
//}

#include<iostream>
#include<vector>

using namespace std;


int main(){
    //vector::capacity()的使用
  vector<int> v(10,5);
  cout<<&v[0]<<endl;
  cout<<v.capacity()<<endl;

  //vector::reserve()的使用
  v.reserve(20);
  cout<<v.capacity()<<endl;
  cout<<&v[0]<<endl;
  vector<int>::iterator vt=v.begin();
  while(vt!=v.end()){
    cout<<*vt<<" ";
    vt++;
  }
  cout<<endl;

  v.resize(30,1);
  cout<<&v[0]<<endl;
  vector<int>::iterator vt1=v.begin();
  while(vt1!=v.end()){
    cout<<*vt1<<" ";
    vt1++;
  }
  cout<<endl;
  return 0;
}



