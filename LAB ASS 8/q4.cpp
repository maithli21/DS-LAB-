#include<iostream>
using namespace std;
class Solution {
public:
bool bst ( TreeNode* root , TreeNode* min , TreeNode* max){
  if ( root == NULL) return true;
if( min != NULL && root -> val <= min -> val) return false;
if( max != NULL && root -> val >= max -> val ) return false;
return (bst(root-> left , min , root) && bst(root -> right , root , max));
}
    bool isValidBST(TreeNode* root) {
        return bst(root , NULL ,NULL);    
    }
};
