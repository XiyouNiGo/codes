#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			this->preorder = preorder;
			for (int i = 0; i < inorder.size(); i++) {
				umap[inorder[i]] = i;
			}
			return recursion(0, 0, inorder.size() - 1);
		}
private:
		vector<int> preorder;
		unordered_map<int, int> umap;	// 中序遍历值与索引的映射 O(1)

		TreeNode* recursion(int root, int left, int right) {
			if (left > right)
				return nullptr;
			TreeNode* node = new TreeNode(preorder[root]);
			int division = umap[preorder[root]];
			node->left = recursion(root + 1, left, division - 1);
			node->right = recursion(root + division - left + 1, division + 1, right);
			return node;
		}
};

int main(int argc, char *argv[])
{
		return 0;
}
