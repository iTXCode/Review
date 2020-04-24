#include<vector>
#include<iostream>
using namespace std; 

class bitSet{
  public:
    bitSet(size_t range)
    :_bits()
    {
      _bits.resize((range>>5)+1);
    }

    //把X对应的为设置为1,表示存在
    void Set(size_t X){
      size_t index=X>>5;
      size_t bitNum=X%32;
      _bits[index] |=(1<<bitNum);
    }

    void ReSet(size_t X){
      size_t index=X>>5;
      size_t bitNum=X%32;
      _bits[index] &=(~(1<<bitNum) );
    }

    //检查X对应的位是否位1
    bool TestBSet(size_t X){
      size_t index=X>>5;
      size_t bitNum=X%32;
      return _bits[index]&(1<<bitNum);
    }
  private:
    vector<int> _bits;
};
