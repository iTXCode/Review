#include"bitSet.hpp"
#include<string>

using namespace std;


template <class K,
class HashFun1,
class HashFun2,
class HashFun3>

class BloomFilter{
  public:

    //k=m*ln2/n 
    //k:哈希函数数量
    //n:range 
    //m:需要的bit位数量
    //m=k*n/ln2--->k*range/0.7 
    BloomFilter(size_t range)
      :_bs(range*5) //减少冲突的发生,采用多开空间的方式
       ,_bitCount(range*5)
  {

  }

    //布隆过滤器的插入
    void Set( const K& key){
      size_t index1=HashFun1()(key)%_bitCount;
      size_t index2=HashFun2()(key)%_bitCount;
      size_t index3=HashFun3()(key)%_bitCount;
      _bs.Set(index1);
      _bs.Set(index2);
      _bs.Set(index3);
    }

    //查找
    bool Test(const K& key){
      size_t index1=HashFun1()(key)%_bitCount;
      if(!_bs.TestSet(index1)){
        return false;
      }
      size_t index2=HashFun2()(key)%_bitCount;
      if(!_bs.TestSet(index2)){
        return false;
      }
      size_t index3=HashFun3()(key)%_bitCount;
      if(!_bs.TestSet(index3)){
        return false;
      }
      return true;  //存在误判
    }

  private:
    bitSet _bs;
    size_t _bitCount;
};

struct HF1{
  size_t operator()(const string& Str){
    size_t hash=0;
    for(const auto& e:Str){
      hash=hash*131+e;
    }
  return hash;
  }
};


struct HF2{
  size_t operator()(const string& Str){
    size_t hash=0;
    for(const auto& e:Str){
      hash=hash*65599+e;
    }
  return hash;
  }
};


struct HF3{
  size_t operator()(const string& Str){
    size_t hash=0;
    size_t magic=63689;
    for(const auto& e:Str){
      hash=hash*magic+e;
      magic*=378551;
    }
  return hash;
  }
};

