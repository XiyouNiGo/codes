#include <bits/stdc++.h>

using namespace std;

int fib1(int n)
{
    if (n <= 2) return 1;
    return fib1(n-1) + fib1(n-2);
}
//尾递归优化
int fib2(int f, int s, int n)
{
    if (n <= 2) return 1;
    if (n == 3) return f+s;
    return fib2(s, f+s, n-1);
}
//带备忘录的递归
int do_fib3(vector<int>& memo, int n)
{
    if (n == 1 || n == 2) return 1;
    if (memo[n]) return memo[n];
    return memo[n] = do_fib3(memo, n-1) + do_fib3(memo, n-2);
}

int fib3(int n)
{
    if (n < 1) return -1;
    vector<int> memo(n+1, 0);
    return do_fib3(memo, n);
}
//备忘录+尾递归
int do_fib4(int f, int s, int n, vector<int>& memo)
{
    if (n <= 2) return 1;
    if (n == 3) return f+s;
    if (memo[n]) return memo[n];
    return memo[n] = do_fib4(s, f+s, n-1, memo);
}

int fib4(int n)
{
    if (n < 1)
        return -1;
    vector<int> memo(n+1, 0);
    return do_fib4(1, 1, n, memo);
}

int main(int argc, char *argv[])
{
    cout << "fib1(5): " << fib1(5) << endl;
    cout << "fib2(1, 1, 5): " << fib2(1, 1, 5) << endl;
    cout << "fib3(5): " << fib3(5) << endl;
    cout << "fib4(5): " << fib4(5) << endl;
    return 0;
}

