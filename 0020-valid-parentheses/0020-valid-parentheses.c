
int ispair(char open, char close) {
    if ((open == '(' && close == ')') || 
        (open == '[' && close == ']') || 
        (open == '{' && close == '}')) {
        return 1;
    }
    return 0;
}

bool isValid(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(sizeof(char) * (len + 1));
    int i_stack = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[i_stack++] = s[i];
        } 
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (i_stack == 0 || !ispair(stack[i_stack - 1], s[i])) {
                free(stack);
                return false;
            }
            i_stack--;
        }
    }

    bool valid = (i_stack == 0);
    free(stack);
    return valid;
}