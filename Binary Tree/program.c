#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int HeightTree(struct TreeNode* root){
    if(!root){return 0;}

    int hleft = HeightTree(root->left);
    int hrigt = HeightTree(root->right);
    
    return hleft > hrigt ? (hleft + 1) : (hrigt +1);
}

bool isBalanced(struct TreeNode* root) {
    if(!root) return true;

    int tleft = HeightTree(root->left);
    int trigt = HeightTree(root->right);
    
    if(abs(tleft - trigt) <= 1){
        return isBalanced(root->left) && isBalanced(root->right);
    }else{
        return false; 
    }
}
