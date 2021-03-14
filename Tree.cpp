#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

public:
      TreeNode *buildTreeHelper(vector<int> preorder, vector<int> inorder, unordered_map<int, int> map, int start, int end)
      {
            if (start > end)
            {
                  return NULL;
            }
            static int preIdx = 0;
            int root_value = preorder[preIdx++];
            TreeNode *root = new TreeNode(root_value);

            if (start == end)
            {
                  return root;
            }
            int in_index = map[root_value];

            root->left = buildTreeHelper(preorder, inorder, map, start, in_index - 1);
            root->right = buildTreeHelper(preorder, inorder, map, in_index + 1, end);

            return root;
      }
      TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder)
      {
            unordered_map<int, int> map;
            for (int i = 0; i < preorder.size(); i++)
            {
                  map[preorder[i]] = i;
            }
            return buildTreeHelper(preorder, inorder, map, 0, preorder.size() - 1);
      }

      void preorder(TreeNode *root)
      {
            if (root)
            {
                  preorder(root->left);
                  cout << root->val << " ";
                  preorder(root->right);
            }
      }
};

int main()
{
      Solution s;
      TreeNode *root = s.buildTree({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7});
      s.preorder(root);
}