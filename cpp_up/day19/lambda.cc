///#include<iostream>
///#include<vector>
///#include<algorithm>
///
///using namespace std;
///
/////仿函数的使用
///
///struct Compare{
///  bool operator()(int a,int b){
///    return a>b;
///  }
///};
///void Test(){
///  vector<int> v={0,-1,-5,9,8,4,2,1};
/// 
///  for(auto& e:v){
///    cout<<e<<" ";
///  }
///  cout<<endl;
///  //对其进行排序可以使用std::sort 
///  cout<<"默认排序:";
///  sort(v.begin(),v.end());
///  for(auto& e:v){
///    cout<<e<<" ";
///  }
///  cout<<endl;
/// 
///  //如果拍排序元素为自定义类型,需要用户定义排序时规则
///  cout<<"仿函数方式排序:"; 
///  sort(v.begin(),v.end(),Compare());
///  for(auto& e:v){
///    cout<<e<<" ";
///  }
///  cout<<endl;
///
///  cout<<"lambda表达式的使用:";
///
///  sort(v.begin(),v.end(),[](int a,int b)->bool{
///      return a>b;
///      });
///  for(auto& e:v){
///    cout<<e<<" ";
///  }
///  cout<<endl;
///
///  int x=10;
///  auto ret=[x](int a)mutable{x*=2;return a+x;};
///  //此处改变了x的值,使用mutable来消除了x的const属性
///  cout<<ret(2)<<endl;
///}
///
///int main(){
///   Test();  
///  return 0;
///}
///
///
/////int main(){
/////  int b=10;
/////  auto fun2=[=,&b](int a,int c)->int{
/////  return b+=a+c;
/////  };
/////
/////  cout<<"fun2(1,2)="<<fun2(1,2)<<endl;
/////}


#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

//class Solution {
//  public:
//    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//      if(matrix.size()==0){
//        return false;
//      }
//
//      int n=matrix.size();  //行数
//      int m=matrix[0].size(); //列数
//      int row=0;  //行数
//      int list=m-1; //列数
//
//      while(row< n ||  list>=0 ){
//        if(matrix[row][list]==target){
//          return true;
//
//        }else if(matrix[row][list]>target){
//          list--;
//
//        }else if(matrix[row][list]<target){
//          row++;
//
//        }
//
//      }
//      return false;
//
//    }
//
//};
//int main(){
//  vector<vector<int>> m{{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
// Solution s;
// vector<int> v{1,2,3,4,5};
// auto it=v.end()-1;
// while(it != v.begin()-1){
//   cout<<*it;
//   it--;
// }
// cout<<endl;
// cout<<s.findNumberIn2DArray(m,10)<<endl;;
// string S("we ");
// S[0]='%';
// S[1]='2';
// S[2]='0';
// cout<<S[0]<<endl;
// S.resize(2*S.size(),'\0');
// S.size();
// for(const auto& e:S){
//   cout<<e;
// }
// cout<<endl;
// return 0;
//
//}
//
 
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<deque>
#include<map>

using namespace std ;



  char firstUniqChar(string s) {
    //暴力破解法
    int num=s.size();
    char ret=' ';
    if(num==0){
      return ret;
    }

    for(int i=0;i<num;i++){
      int flag=0;
      for(int j=i+1;j<num;j++){

        if(s[i]==s[j]){
          break;
        }
        if(j==num-1&&s[i]!=s[j]){
          flag=1;
        }
      }
      if(flag==1){
        ret=s[i];
        break;
      }
    }
    return ret;
  }





 


int main(){
  string s="aadadaad";
  cout<<firstUniqChar(s)<<endl; 
  return 0;
}
