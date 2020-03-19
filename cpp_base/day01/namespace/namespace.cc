#include<iostream>

namespace A{
  int a=10;
}

namespace A{
  int b=10;
}

namespace B{
  namespace C{
    int a=1;
  }
}
int main(){

  std::cout<<A::a<<A::b<<std::endl;
  std::cout<<B::C::a<<std::endl;
  return 0;
}
