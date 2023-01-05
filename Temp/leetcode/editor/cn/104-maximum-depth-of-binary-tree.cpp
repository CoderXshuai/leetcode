#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
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
    int res = 0;

    int maxDepth(TreeNode *root) {
        queue q =
                traverse(root, 0);
        return res;
    }

    int traverse(TreeNode *root, int n) {
        if (root != nullptr) {
            int m = traverse(root->left, n + 1);
            m--;
            traverse(root->right, m + 1);
        }
        res = max(res, n);
        return n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    TreeNode root = TreeNode(3);
    auto left = TreeNode(9);
    auto right = TreeNode(20);
    auto node1 = TreeNode(15);
    auto node2 = TreeNode(17);
    right.left = &node1;
    right.right = &node2;
    TreeNode *p1 = &left;
    TreeNode *p2 = &right;
    root.left = p1;
    root.right = p2;
    s.maxDepth(&root);
}