#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
      // O(logN) O(1)
      int left = 0, right = numbers.size() - 1;
      int middle;
      while (left < right) {
        // 只有右排序数组
        if (numbers[0] < numbers[numbers.size() - 1])
        return numbers[0];
        middle = left + (right - left) / 2;
        if (numbers[middle] > numbers[left]) {
          left = middle + 1;
        } else if (numbers[middle] < numbers[left]) {
          right = middle;
        } else {
          left++;
        }
      }
      return numbers[middle];
    }
};

int main(int argc, char* argv[])
{
	return 0;
}
