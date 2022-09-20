#include <iostream>
using namespace std;
int main() {
  int thumb_up = 0, review = 0;
  int n = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int cur = 0;
    cin >> cur;
    if (cur == 2) {
      thumb_up++;
    } else if (cur == 3) {
      if (thumb_up > review) {
        thumb_up++;
      } else if (thumb_up < review) {
        review++;
      } else if (thumb_up == review) {
        thumb_up++;
        review++;
      }
    } else if (cur == 1) {
      review++;
    }
  }
  cout << review << " " << thumb_up;
}