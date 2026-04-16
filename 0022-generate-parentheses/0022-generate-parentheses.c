/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(int n, int* returnSize, char** result, char* currentstr, int open, int close, int index){
    if(index == 2 * n){
        currentstr[index] = '\0';
        result[*returnSize] = strdup(currentstr);
        (*returnSize)++;
        return;
    }
    if(open < n){
        currentstr[index] = '(';
        backtrack(n, returnSize, result, currentstr, open + 1, close, index + 1);
    }
    if(open > close){
        currentstr[index] = ')';
        backtrack(n, returnSize, result, currentstr, open, close + 1, index + 1);
    }
}


char** generateParenthesis(int n, int* returnSize) {
    char** result = (char**)malloc(5000 * sizeof(char*));
    *returnSize = 0;
    char* currentstr = (char*)malloc((2 * n + 1) * sizeof(char));
    backtrack(n, returnSize, result, currentstr, 0, 0, 0);
    free(currentstr);
    return result;
}