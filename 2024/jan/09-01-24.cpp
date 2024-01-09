/*
Title: Leaf-Similar Trees
Link: https://leetcode.com/problems/leaf-similar-trees/description/?envType=daily-question&envId=2024-01-09

Problem: Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 Example 1:


Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
Example 2:


Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
 

Constraints:

The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getLeafNode(TreeNode* root, vector<int>& tree){
        if(root == NULL){
            return;
        }

        if(root->left ==NULL && root->right==NULL){
            tree.push_back(root->val);
        }

        getLeafNode(root->left,tree);
        getLeafNode(root->right,tree);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;

        getLeafNode(root1,tree1);
        getLeafNode(root2,tree2);

        if(tree1.size()!=tree2.size()){
            return false;
        }

        if(tree1 != tree2){
            return false;
        }

        return true;
    }
};