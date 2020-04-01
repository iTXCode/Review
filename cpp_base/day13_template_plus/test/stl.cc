#include<iostream>
#include<string.h>

// 代表内置类型
 struct __true_type {};
 // 代表自定义类型
 struct __false_type {};
 template <class type>
 struct __type_traits
 {
 typedef __false_type is_POD_type;
 };
 // 对所有内置类型进行特化
 template<>
 struct __type_traits<char> {
 typedef __true_type is_POD_type;
 };
 template<>
 struct __type_traits<signed char> {
 typedef __true_type is_POD_type;
 };
 template<>
 struct __type_traits<unsigned char> {
 typedef __true_type is_POD_type;
 };
 template<>
 struct __type_traits<int>
{typedef __true_type is_POD_type;
};
template<>
struct __type_traits<float> {
  typedef __true_type is_POD_type;

};
template<>
struct __type_traits<double> {
  typedef __true_type is_POD_type;

};

// 注意：在重载内置类型时，所有的内置类型都必须重载出来，包括有符号和无符号，比如：对于int类型，必
// 须特化三个，int -- signed int -- unsigned int
//  在需要区分内置类型与自定义类型的位置，标准库通常都是通过__true_type与__false_type给出一对重载
// 
//  函数，然后用一个通用函数对其进行封装
//  注意：第三个参数可以不提供名字，该参数最主要的作用就是让两个_copy函数形成重载

template<class T>
void _copy(T* dst, T* src, size_t n, __true_type) {
  memcpy(dst, src, n*sizeof(T));

}
template<class T>
void _copy(T* dst, T* src, size_t n, __false_type) {
  for (size_t i = 0; i < n; ++i)
    dst[i] = src[i];

}
template<class T>
void Copy(T* dst, T* src, size_t n) {
  _copy(dst, src, n, __type_traits<T>::is_POD_type());

}



