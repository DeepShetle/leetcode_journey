/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}
int maxDepth(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    else{
        return max(maxDepth(root -> left) + 1, maxDepth(root -> right) + 1);
    }
}