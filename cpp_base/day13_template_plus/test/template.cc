#include<iostream>
#include<string.h>
using namespace std;

struct TrueType{
  static bool Get(){
    return false;
  }
};


struct FalseType{
  static bool Get(){
    return false;
  }
};

template <class T>
struct TypeTraits{
  typedef FalseType IsPODType;
};
template<class T>
void Copy(T* dst, const T* src, size_t size) {
  if(TypeTraits<T>::IsPODType::Get())
    memcpy(dst, src, sizeof(T)*size);
  else
  {for(size_t i = 0; i < size; ++i)
    dst[i] = src[i];
  }

}
int main()
{
  int a1[] = {1,2,3,4,5,6,7,8,9,0};
  int a2[10];
  Copy(a2, a1, 10); 
  string s1[] = {"1111", "2222", "3333", "4444"};
  string s2[4];
  Copy(s2, s1, 4);
  return 0; 

}
