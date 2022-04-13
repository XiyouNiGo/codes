#include <stdio.h>
#define PI 3.14
int main() {
  int arr[105];  // This is an array
  double res;
  for (int i = 0; i < 10; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] < 5)
      res = res + arr[i];
    else
      res = res + arr[i];
  }
  res = res / PI;
  printf("%.2lf", res); /*Keep two decimal places*/
  return 0;
}