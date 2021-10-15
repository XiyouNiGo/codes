/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-06 21:02:07
 * @LastEditTime: 2021-10-06 21:12:00
 * @Description: file content
 * @FilePath: /leetcode/week6/bit_operation.cpp
 */
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  {
    // 判断是否异号
    cout << "(1 ^ -1) = " << ((1 ^ -1) < 0) << endl;
    cout << "(1 ^ 2) = " << ((1 ^ 2) < 0) << endl;
  }
  {
    // swap
    int a = 1, b = 2;
    a ^= b;
    b ^= a;
    a ^= b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
  }
  {
    // 加一
    int n = 1;
    n = -~n;
    cout << "n = " << n << endl;
  }
  {
    // 减一
    int n = 1;
    n = ~-n;
    cout << "n = " << n << endl;
  }
  return 0;
}