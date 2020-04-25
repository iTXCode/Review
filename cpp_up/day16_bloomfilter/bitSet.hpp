#pragma once

#include<vector>
#include<iostream>
#include<string>
using namespace std; 

class bitSet{
  public:
    bitSet(size_t range)
    :_bits()
     ,_bitCount(range)
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
    bool TestSet(size_t X){
      size_t index=X>>5;
      size_t bitNum=X%32;
      return _bits[index]&(1<<bitNum);
    }

    //获取位图中比特位的总个数
    size_t Size()const{
      return _bitCount;
    }
   

  private:
    vector<int> _bits; 
    size_t _bitCount;
};
