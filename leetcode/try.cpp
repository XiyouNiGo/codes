#include <bits/stdc++.h>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int main(int argc, char *argv[])
{
    struct TreeNode a(1), b(1);
    &a < &b;
    return 0;
}

