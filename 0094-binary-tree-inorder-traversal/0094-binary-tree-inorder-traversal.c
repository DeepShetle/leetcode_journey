/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //Hàm phụ đếm tổng số node trên tree
 int countnode(struct TreeNode* root){
    if(root == NULL) return 0;
    return 1 + countnode(root -> left) + countnode(root -> right);
 }
 //Duyệt Inorder và điền giá trị vào mảng
 void inorder(struct TreeNode* root, int* result, int* index){
    if(root == NULL) return;
    inorder(root -> left, result, index);
    result[*index] = root -> val;
    (*index)++;
    inorder(root -> right, result, index);
 }

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int totalnodes = countnode(root);

    int* result = (int*)malloc(totalnodes * sizeof(int));
    int currindex = 0;
    inorder(root, result, &currindex);
    *returnSize = totalnodes;
    return result;



}