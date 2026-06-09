/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b){
    return (a > b) ? a : b;
}
int check_height(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    else{
        return max(check_height(root -> left), check_height(root -> right)) + 1;
    }
}
bool isBalanced(struct TreeNode* root) {
    if(root == NULL){
        return true;
    }
    else{
        return (abs(check_height(root -> left) - check_height(root -> right)) <= 1) && isBalanced(root -> left) && isBalanced(root -> right);
    }
}