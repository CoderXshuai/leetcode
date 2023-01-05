#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "TreeNode.h"

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res;

    int diameterOfBinaryTree(TreeNode *root) {
        if (root != nullptr) {
            int left_size = diameterOfBinaryTree(root->left);
            int right_size = diameterOfBinaryTree(root->right);

        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
}