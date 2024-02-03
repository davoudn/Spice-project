#include <iostream>
#include <new>
#include <string>
#include <type_traits>
 
struct A{};
struct B{};

template <typename T>
struct is_A{
	static const bool value = false;
};

template <>
struct is_A<A>{
	static const bool value = true;
};

template <typename T>
typename std::enable_if< is_A<T>::value,T>::type 
f(T t){
      return t;
}


int main()
{
B a;
	f(a);
}
