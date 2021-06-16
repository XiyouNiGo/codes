#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  //创建方式
  tuple<int, char, double> t1(10, 'a', 3.14);
  auto t2 = make_tuple(20, 'b', 6.28);

  //元素个数
  cout << tuple_size<decltype(t1)>::value << endl;

  //get<T> : T为非类型参数，必须在编译时确定
  cout << get<0>(t1) << " ";
  cout << get<1>(t1) << " ";
  cout << get<2>(t1) << endl;
//  for (int i = 0; i < 3; ++i)
//    cout << get<i>(t1) << endl;

  //获取元素类型
  std::tuple_element<0, decltype(t1)>::type i;
  i = std::get<1>(t1);

  //使用tie
  //利用ignore忽略对应元素
  char c;
  double d;
  tie(ignore, c, d) = t1;

  //比较大小
  cout << (t1 < t2) << endl;

  //改变tuple的值
  get<1>(t1) = get<1>(t2);
  
  return 0;
}
