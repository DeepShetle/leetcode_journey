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
int dfs(struct TreeNode* node, int* max_diameter){
    if(node == NULL){
        return 0;
    }
    int left_height = dfs(node -> left, max_diameter);
    int right_height = dfs(node -> right, max_diameter);
    int dia = left_height + right_height;
    if(dia > *max_diameter){
        *max_diameter = dia;
    }
    return 1 + max(left_height, right_height);
}
int diameterOfBinaryTree(struct TreeNode* root) {
    int return_dia = 0;
    int tree_height = dfs(root, &return_dia);
    return return_dia;
}