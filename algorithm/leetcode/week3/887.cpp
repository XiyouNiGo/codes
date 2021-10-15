#include <bits/stdc++>

using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        int eggNum = K, floorNum = N;
        if(eggNum < 1 || floorNum < 1)
            return 0;
        vector<vector<int>> cache(eggNum + 1, vector<int>(floorNum + 1, 0));
        for(int i = 1; i <= eggNum; i ++){
            for(int j = 1; j <= floorNum; j ++)
                cache[i][j] = j;
        }
        for(int n = 2; n <= eggNum; n ++){
            for (int m = 1; m <= floorNum; m ++){
                for(int k = 1; k < m; k ++){
                    cache[n][m] = min(cache[n][m], max(cache[n - 1][k - 1], cache[n][m - k]) + 1);
                }
            }
        }
        return cache[eggNum][floorNum];
    }
};

