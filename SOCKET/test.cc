#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std; 


int main(){

  vector<vector<int>> ret{{1,100},{11,22},{1,11},{2,12}};
  sort(ret.begin(),ret.end(),[](vector<int>& a,vector<int>& b ){
      if(a[0]!=b[0]){
                      return a[0]<b[0];
                                  
      }
                  return a[1]<b[1];
                          
      });
  for(auto& e:ret){
    for(auto& x:e){
      cout<<x;
    } 
    cout<<endl;
  }
  return 0;
}
