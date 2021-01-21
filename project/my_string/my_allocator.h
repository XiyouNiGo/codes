//
// Created by nigo on 2021/1/20.
//

#ifndef MY_STRING__MY_ALLOCATOR_H_
#define MY_STRING__MY_ALLOCATOR_H_

template <typename T>
class my_allocator {
 public:

  typedef T value_type;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef T& reference;
  typedef const T& const_reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  //对不同类型采用同种分配策略
  template <typename U>
  class rebind {
    typedef my_allocator<U> other;
  };

  pointer allocate(size_type size) {
    pointer p = static_cast<pointer>(::operator new[](size * sizeof(T)));
    if (p == nullptr)
	  throw std::bad_alloc();
    return p;
  }

  void deallocate(pointer p) {
    ::operator delete[](p);
  }

  void destory(pointer p) {
    p->~T();
  }

//  void construct(pointer p, const_reference value) {
//    new((void*)p) T(value);
//  }

  template <class U, class... Args>
  void construct (U* p, Args&&... args) {
    ::new ((void*)p) U(std::forward<Args>(args)...);
  }

  pointer address(const_reference cr) {
    return &cr;
  }

  size_type max_size() const {
	return UINT64_MAX / sizeof(T);
  }
};

#endif //MY_STRING__MY_ALLOCATOR_H_
