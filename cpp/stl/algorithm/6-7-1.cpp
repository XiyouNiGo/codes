#include <bits/stdc++.h>

using namespace std;

// functor
template <class T>
struct display {
  void operator()(const T& x) const { cout << x << ' '; }
};

struct even {
  bool operator()(int x) const { return x % 2 ? false : true; }
};

class even_by_two {
 public:
  int operator()() const { return _x += 2; }

 private:
  static int _x;
};

int even_by_two::_x = 0;

int main() {
  int ia[] = {0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8};
  vector<int> iv(ia, ia + sizeof(ia) / sizeof(int));

  // 相邻元素值相等的第一个元素
  cout << *adjacent_find(iv.begin(), iv.end()) << endl;
  cout << *adjacent_find(iv.begin(), iv.end(), equal_to<int>()) << endl;

  cout << count(iv.begin(), iv.end(), 6) << endl;
  cout << count_if(iv.begin(), iv.end(), bind2nd(less<int>(), 7)) << endl;

  cout << *find(iv.begin(), iv.end(), 4) << endl;
  cout << *find_if(iv.begin(), iv.end(), bind2nd(greater<int>(), 2)) << endl;

  vector<int> iv2(ia + 6, ia + 8);
  cout << *(find_end(iv.begin(), iv.end(), iv2.begin(), iv2.end()) + 3) << endl;

  cout << *(find_first_of(iv.begin(), iv.end(), iv2.begin(), iv2.end()) + 3)
       << endl;

  for_each(iv.begin(), iv.end(), display<int>());
  cout << endl;
  
  // 第三参数为零参数的仿函数
  generate(iv2.begin(), iv2.end(), even_by_two());
  for_each(iv2.begin(), iv2.end(), display<int>());
  cout << endl;

  generate_n(iv2.begin(), 3, even_by_two());
  for_each(iv2.begin(), iv2.end(), display<int>());
  cout << endl;

  // erase：删除并释放资源
  // remove：将不符合条件的元素移至末端（效率更高）
  remove(iv.begin(), iv.end(), 6);
  for_each(iv.begin(), iv.end(), display<int>());
  cout << endl;

  vector<int> iv3(12);
  remove_copy(iv.begin(), iv.end(), iv3.begin(), 6);
  for_each(iv3.begin(), iv3.end(), display<int>());
  cout << endl;

  remove_if(iv.begin(), iv.end(), bind2nd(less<int>(), 6));
  for_each(iv.begin(), iv.end(), display<int>());
  cout << endl;

  remove_copy_if(iv.begin(), iv.end(), iv3.begin(), bind2nd(less<int>(), 7));
  for_each(iv3.begin(), iv3.end(), display<int>());
  cout << endl;

  replace(iv.begin(), iv.end(), 6, 3);
  for_each(iv.begin(), iv.end(), display<int>());
  cout << endl;

  replace_copy(iv.begin(), iv.end(), iv3.begin(), 3, 5);
  for_each(iv3.begin(), iv3.end(), display<int>());
  cout << endl;

  replace_if(iv.begin(), iv.end(), bind2nd(less<int>(), 5), 2);
  for_each(iv.begin(), iv.end(), display<int>());
  cout << endl;

  replace_copy_if(iv.begin(), iv.end(), iv3.begin(),
                  bind2nd(equal_to<int>(), 8), 9);
  for_each(iv3.begin(), iv3.end(), display<int>());
  cout << endl;

  reverse(iv.begin(), iv.end());
  for_each(iv.begin(), iv.end(), display<int>());
  cout << endl;

  reverse_copy(iv.begin(), iv.end(), iv3.begin());
  for_each(iv3.begin(), iv3.end(), display<int>());
  cout << endl;

  rotate(iv.begin(), iv.begin() + 4, iv.end());
  for_each(iv.begin(), iv.end(), display<int>());
  cout << endl;

  rotate_copy(iv.begin(), iv.begin() + 5, iv.end(), iv3.begin());
  for_each(iv3.begin(), iv3.end(), display<int>());
  cout << endl;

  int ia2[3] = {2, 8};
  vector<int> iv4(ia2, ia2 + 2);
  cout << *search(iv.begin(), iv.end(), iv4.begin(), iv4.end()) << endl;
  cout << *search_n(iv.begin(), iv.end(), 2, 8) << endl;
  cout << *search_n(iv.begin(), iv.end(), 3, 8, less<int>()) << endl;

  swap_ranges(iv4.begin(), iv4.end(), iv.begin());
  for_each(iv.begin(), iv.end(), display<int>());
  cout << endl;
  for_each(iv4.begin(), iv4.end(), display<int>());
  cout << endl;

  transform(iv.begin(), iv.end(), iv.begin(), bind2nd(minus<int>(), 2));
  for_each(iv.begin(), iv.end(), display<int>());
  cout << endl;

  transform(iv.begin(), iv.end(), iv.begin(), iv.begin(), plus<int>());
  for_each(iv.begin(), iv.end(), display<int>());
  cout << endl;

  vector<int> iv5(ia, ia + sizeof(ia) / sizeof(int));
  vector<int> iv6(ia + 4, ia + 8);
  vector<int> iv7(15);
  for_each(iv5.begin(), iv5.end(), display<int>());
  cout << endl;
  for_each(iv6.begin(), iv6.end(), display<int>());
  cout << endl;

  // max接受参数为value，而不是由迭代器构成的区间
  cout << *max_element(iv5.begin(), iv5.end()) << endl;
  cout << *min_element(iv5.begin(), iv5.end()) << endl;

  // 判断s2是否涵盖于s1（必须是有序集合）
  cout << includes(iv5.begin(), iv5.end(), iv6.begin(), iv6.end()) << endl;

  merge(iv5.begin(), iv5.end(), iv6.begin(), iv6.end(), iv7.begin());
  for_each(iv7.begin(), iv7.end(), display<int>());
  cout << endl;

  // stable_partition
  partition(iv7.begin(), iv7.end(), even());
  for_each(iv7.begin(), iv7.end(), display<int>());
  cout << endl;

  // 去除连续重复元素
  unique(iv5.begin(), iv5.end());
  for_each(iv5.begin(), iv5.end(), display<int>());
  cout << endl;
  
  unique_copy(iv5.begin(), iv5.end(), iv7.begin());
  for_each(iv7.begin(), iv7.end(), display<int>());
  cout << endl;
}