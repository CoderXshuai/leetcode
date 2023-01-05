//
// Created by CoderXhuai on 2022/12/7.
//

#ifndef CPP_TREENODE_H
#define CPP_TREENODE_H

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //CPP_TREENODE_H



