#include<iostream>
using namespace std;
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!= NULL && root -> val != val){
            root = val < root->val ? root-> left : root -> right;
        }
        return root;
        }



 TreeNode* minimumelement(TreeNode* root){
        if(root == NULL) return -1;
        if(root -> left) minimumelement(root->left);
        else return root -> data;
    }


 TreeNode* maximumelement(TreeNode* root){
        if(root == NULL) return -1;
        if(root -> right) maximumelement(root->right);
        else return root -> data;
    } 

TreeNode* inordersuccessor(TreeNode* root , TreeNode* p){
    TreeNode* successor = NULL;
  while(root != NULL){
      if( p-> val >= root -> val){
        root = root -> right;
      }
    else{
      successor = root;
      root = root -> left;
    }
  }
  return successor;

  TreeNode* inorderpredeccessor(TreeNode* root , TreeNode* p){
    TreeNode* predeccessor = NULL;
  while(root != NULL){
      if( p-> val <= root -> val){
        root = root -> left;
      }
    else{
      predeccessor = root;
      root = root -> right;
    }
  }
  return predeccessor;
};
