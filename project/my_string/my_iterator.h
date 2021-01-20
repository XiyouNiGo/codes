//
// Created by nigo on 2021/1/20.
//

#ifndef MY_STRING__MY_ITERATOR_H_
#define MY_STRING__MY_ITERATOR_H_

#include "iterator"

template <typename T>
class random_access_iterator {
  
 public:

  typedef size_t size_type;
  typedef T value_type;
  typedef ptrdiff_t difference_type;
  typedef T* pointer;
  typedef const T*  const_pointer;
  typedef T& reference;
  typedef std::random_access_iterator_tag iterator_category;

 private:

  pointer _container;	//容器首地址
  size_type _size;		//容器大小
  size_type _index;		//迭代器下标
  const value_type _end_val = 0;	//尾后元素

 public:

  //使用默认形参应对多参数
  //同时禁止默认构造函数
  random_access_iterator() = delete;

  random_access_iterator(const_pointer container = nullptr,
						size_type size = 0, size_type index = 0) {
    _container = const_cast<pointer>(container);
    _size = size;
    _index = index;
  }

  random_access_iterator(const random_access_iterator<T> &cri) {
    _container = const_cast<pointer>(cri._container);
    _size = cri._size;
    _index = cri._index;
  }

  random_access_iterator<T> &operator=(const random_access_iterator<T> &cri) {
    _container = const_cast<pointer>(cri._container);
    _size = cri._size;
    _index = cri._index;
    return *this;
  }

  bool operator==(const random_access_iterator<T> &cri) const {
    return (_container == cri._container) && (_index == cri._index) && (_size = cri._size);
  }

  bool operator!=(const random_access_iterator<T> &cri) const {
    return !operator==(cri);
  }

  bool operator<(const random_access_iterator<T> &cri) const {
	if (_container != cri._container || _size != cri._size)
	  throw std::logic_error("iterator incomparable");
    return _index < cri._index;
  }

  bool operator<=(const random_access_iterator<T> &cri) const {
	if (_container != cri._container || _size != cri._size)
	  throw std::logic_error("iterator incomparable");
    return _index <= cri._index;
  }

  bool operator>(const random_access_iterator<T> &cri) const {
	if (_container != cri._container || _size != cri._size)
	  throw std::logic_error("iterator incomparable");
    return _index > cri._index;
  }

  bool operator>=(const random_access_iterator<T> &cri) const {
	if (_container != cri._container || _size != cri._size)
	  throw std::logic_error("iterator incomparable");
    return _index > cri._index;
  }

  random_access_iterator<T> &operator+=(difference_type offset) {
    return do_addition(*this, offset);
  }

  random_access_iterator<T> operator+(difference_type offset) {
    random_access_iterator<T> temp(*this);
    return do_addition(temp, offset);
  }

  //++++i正确
  random_access_iterator<T> &operator++() {
	return do_addition(*this, 1);
  }

  //后缀++：形参只是语法要求
  //返回const类型：避免i++++
  const random_access_iterator<T> &operator++(int) {
    random_access_iterator<T> temp(*this);
    do_addition(*this, 1);
	return temp;
  }

  random_access_iterator<T> &operator-=(difference_type offset) {
	return do_subtraction(*this, offset);
  }

  random_access_iterator<T> operator-(difference_type offset) {
	random_access_iterator<T> temp(*this);
	return do_subtraction(temp, offset);
  }

  random_access_iterator<T> &operator--() {
	return do_subtraction(*this, 1);
  }

  const random_access_iterator<T> &operator--(int) {
	random_access_iterator<T> temp(*this);
	do_subtraction(*this, 1);
	return temp;
  }

  difference_type operator-(const random_access_iterator<T> &cri) const {
	if (_container == nullptr)
	  throw std::logic_error("invalid address");
	if (_container != cri._container || _size != cri._size)
	  throw std::logic_error("iterator incomparable");
	return _index - cri._index;
  }

  reference operator*() const {
	if (_index > _size || _index < 0)
	  throw std::out_of_range("cross the border");
	//尾后元素设为0
	if (_index == _size)
	  return const_cast<reference>(_end_val);
	return *(_container + _index);
  }

  reference operator[](difference_type offset) const {
	size_type index = _index + offset;
	if (index > _size || index < 0)
	  throw std::out_of_range("cross the border");
	return *(_container + index);
  }

  //重载成员访问运算符(非静态、无形参）
  //若返回原始指针，将右操作数当作指针所指类型进行访问
  //若返回其他对象实例，继续调用operator->()
  pointer operator->() {
    return &operator*();
  }

  void advance(difference_type offset) {
    do_addition(*this, offset);
  }

  random_access_iterator<T> next() {
    random_access_iterator<T> temp(*this);
    return do_addition(temp, 1);
  }

  random_access_iterator<T> prev() {
    random_access_iterator<T> temp(*this);
    return do_subtraction(temp, 1);
  }

  static difference_type distance(random_access_iterator<T> first,
								  random_access_iterator<T> last) {
    return last - first;
  }

 private:

  static random_access_iterator<T> &do_addition(random_access_iterator<T> &ri,
												difference_type offset) {
	if (ri._container == nullptr)
	  throw std::logic_error("invalid address");
	size_type index = ri._index + offset;
	//允许尾后指针
	if (index > ri._size || index < 0)
	  throw std::out_of_range("cross the border");
	ri._index = index;
	return ri;
  }

  static random_access_iterator<T> &do_subtraction(random_access_iterator<T> &ri,
												   difference_type offset) {
	if (ri._container == nullptr)
	  throw std::logic_error("invalid address");
	size_type index = ri._index - offset;
	//允许尾后指针
	if (index > ri._size || index < 0)
	  throw std::out_of_range("cross the border");
	ri._index = index;
	return ri;
  }

};

template <typename T>
class reverse_random_access_iterator {

 public:

  typedef size_t size_type;
  typedef T value_type;
  typedef ptrdiff_t difference_type;
  typedef T* pointer;
  typedef const T*  const_pointer;
  typedef T& reference;
  typedef std::random_access_iterator_tag iterator_category;

 private:

  pointer _container;	//容器首地址
  size_type _size;		//容器大小
  size_type _index;		//迭代器下标
  const value_type _end_val = 0;	//尾后元素

 public:

  //使用默认形参应对多参数
  //同时禁止默认构造函数
  reverse_random_access_iterator() = delete;

  reverse_random_access_iterator(const_pointer container = nullptr,
						 size_type size = 0, size_type index = 0) {
	_container = const_cast<pointer>(container);
	_size = size;
	_index = index;
  }

  reverse_random_access_iterator(const reverse_random_access_iterator<T> &cri) {
	_container = const_cast<pointer>(cri._container);
	_size = cri._size;
	_index = cri._index;
  }

  reverse_random_access_iterator<T> &operator=(const reverse_random_access_iterator<T> &cri) {
	_container = const_cast<pointer>(cri._container);
	_size = cri._size;
	_index = cri._index;
	return *this;
  }

  bool operator==(const reverse_random_access_iterator<T> &cri) const {
	return (_container == cri._container) && (_index == cri._index) && (_size == cri._size);
  }

  bool operator!=(const reverse_random_access_iterator<T> &cri) const {
	return !operator==(cri);
  }

  bool operator<(const reverse_random_access_iterator<T> &cri) const {
	if (_container != cri._container || _size != cri._size)
	  throw std::logic_error("iterator incomparable");
	return _index < cri._index;
  }

  bool operator<=(const reverse_random_access_iterator<T> &cri) const {
	if (_container != cri._container || _size != cri._size)
	  throw std::logic_error("iterator incomparable");
	return _index <= cri._index;
  }

  bool operator>(const reverse_random_access_iterator<T> &cri) const {
	if (_container != cri._container || _size != cri._size)
	  throw std::logic_error("iterator incomparable");
	return _index > cri._index;
  }

  bool operator>=(const reverse_random_access_iterator<T> &cri) const {
	if (_container != cri._container || _size != cri._size)
	  throw std::logic_error("iterator incomparable");
	return _index > cri._index;
  }

  reverse_random_access_iterator<T> &operator+=(difference_type offset) {
	return do_addition(*this, offset);
  }

  reverse_random_access_iterator<T> operator+(difference_type offset) {
	reverse_random_access_iterator<T> temp(*this);
	return do_addition(temp, offset);
  }

  //++++i正确
  reverse_random_access_iterator<T> &operator++() {
	return do_addition(*this, 1);
  }

  //后缀++：形参只是语法要求
  //返回const类型：避免i++++
  const reverse_random_access_iterator<T> &operator++(int) {
	reverse_random_access_iterator<T> temp(*this);
	do_addition(*this, 1);
	return temp;
  }

  reverse_random_access_iterator<T> &operator-=(difference_type offset) {
	return do_subtraction(*this, offset);
  }

  reverse_random_access_iterator<T> operator-(difference_type offset) {
	reverse_random_access_iterator<T> temp(*this);
	return do_subtraction(temp, offset);
  }

  reverse_random_access_iterator<T> &operator--() {
	return do_subtraction(*this, 1);
  }

  const reverse_random_access_iterator<T> &operator--(int) {
	reverse_random_access_iterator<T> temp(*this);
	do_subtraction(*this, 1);
	return temp;
  }

  difference_type operator-(const reverse_random_access_iterator<T> &cri) const {
	if (_container == nullptr)
	  throw std::logic_error("invalid address");
	if (_container != cri._container || _size != cri._size)
	  throw std::logic_error("iterator incomparable");
	return _index - cri._index;
  }

  reference operator*() const {
	if (_index > _size || _index < 0)
	  throw std::out_of_range("cross the border");
	//尾后元素设为0
	if (_index == _size)
	  return const_cast<reference>(_end_val);
	return *(_container - _index);
  }

  reference operator[](difference_type offset) const {
	size_type index = _index + offset;
	if (index > _size || index < 0)
	  throw std::out_of_range("cross the border");
	return *(_container - index);
  }

  //重载成员访问运算符(非静态、无形参）
  //若返回原始指针，将右操作数当作指针所指类型进行访问
  //若返回其他对象实例，继续调用operator->()
  pointer operator->() {
	return &operator*();
  }

  void advance(difference_type offset) {
	do_addition(*this, offset);
  }

  reverse_random_access_iterator<T> next() {
	reverse_random_access_iterator<T> temp(*this);
	return do_addition(temp, 1);
  }

  reverse_random_access_iterator<T> prev() {
	reverse_random_access_iterator<T> temp(*this);
	return do_subtraction(temp, 1);
  }

  static difference_type distance(reverse_random_access_iterator<T> first,
								  reverse_random_access_iterator<T> last) {
	return last - first;
  }

 private:

  static reverse_random_access_iterator<T> &do_addition(reverse_random_access_iterator<T> &ri,
												difference_type offset) {
	if (ri._container == nullptr)
	  throw std::logic_error("invalid address");
	size_type index = ri._index + offset;
	//允许尾后指针
	if (index > ri._size || index < 0)
	  throw std::out_of_range("cross the border");
	ri._index = index;
	return ri;
  }

  static reverse_random_access_iterator<T> &do_subtraction(reverse_random_access_iterator<T> &ri,
												   difference_type offset) {
	if (ri._container == nullptr)
	  throw std::logic_error("invalid address");
	size_type index = ri._index - offset;
	//允许尾后指针
	if (index > ri._size || index < 0)
	  throw std::out_of_range("cross the border");
	ri._index = index;
	return ri;
  }

};

#endif //MY_STRING__MY_ITERATOR_H_
