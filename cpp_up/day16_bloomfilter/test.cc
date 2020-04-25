#include"BloomFilter.hpp"

void Test(){
  BloomFilter<string,HF1,HF2,HF3> bf(100);
  string str1="https://mp.csdn.net/console/article";
  string str2="http://www.cplusplus.com/search.do?q=resize";
  string str3="https://cn.bing.com/search?FORM=U474DF&PC=U474&q=resize";
  string str4="https://github.com/iTXCode/Review/blob/master/cpp_up/day15_hash/bitSet.hpp";

  bf.Set(str1);
  bf.Set(str2);
  bf.Set(str3);

  cout<<bf.Test(str3)<<endl;
  cout<<bf.Test(str4)<<endl;
}
int main(){
  Test();
  return 0;
}
