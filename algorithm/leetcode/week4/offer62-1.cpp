#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        int x = 0;
        for (int i = 2; i <= n; i++) {
            x = (x + m) % i;
        }
        return x;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
