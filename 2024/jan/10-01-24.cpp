/*
Title: Amount of Time for Binary Tree to Be Infected
URL: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10

Problem : You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

	The node is currently uninfected.
	The node is adjacent to an infected node.

Return the number of minutes needed for the entire tree to be infected.

 
Example 1:

Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

Example 2:

Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.

 
Constraints:

	The number of nodes in the tree is in the range [1, 105].
	1 <= Node.val <= 105
	Each node has a unique value.
	A node with a value of start exists in the tree.
*/

#include<bits/stdc++.h>
using namespace std;

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
    bool findRoot(TreeNode* root,int start,vector<int> &position){
        if(root==NULL) return 0;
        if(root->val==start) return 1;

        position.push_back(0);
        bool left=findRoot(root->left,start,position);
        if(!left) position.pop_back();
        else return 1;

        position.push_back(1);
        bool right=findRoot(root->right,start,position);
        if(!right) position.pop_back();
        else return 1;
        return 0;
    }

    int recSol(TreeNode* root){
        if(root==NULL) return 0;
        int left=recSol(root->left);
        int right=recSol(root->right);
        return 1+max(left,right);
    }

    int amountOfTime(TreeNode* root, int start) {
        int ans=0;
        bool flag=0;
        //position array stores the path 0 -> left || 1-> right
        vector<int> position;
        findRoot(root,start,position);
        int n=position.size();
        //We are finding the longest path by considering all nodes individually in the path between the root and the starting node.
        for(int i=0;i<n;i++){
            if(position[i]==0){
                ans=max(ans,recSol(root->right)+n-i);
                root=root->left;
            }
            else {
                ans=max(ans,recSol(root->left)+n-i);
                root=root->right;
            }
        }
        return max(ans,max(recSol(root->left),recSol(root->right)));
    }
};

