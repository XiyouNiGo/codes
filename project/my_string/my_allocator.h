//
// Created by nigo on 2021/1/20.
//

#ifndef MY_STRING__MY_ALLOCATOR_H_
#define MY_STRING__MY_ALLOCATOR_H_

template <typename T>
class my_allocator {
 public:
  typedef size_t size_type;
  typedef T* pointer;
  typedef const T* const_pointer;

  pointer allocate(size_type size) {
    pointer p = static_cast<pointer>(operator new[](size * sizeof(T)));
    if (p == nullptr)
	  throw std::bad_alloc();
    return p;
  }

  void deallocate(pointer p) {
    operator delete[](p);
  }
};

#endif //MY_STRING__MY_ALLOCATOR_H_
