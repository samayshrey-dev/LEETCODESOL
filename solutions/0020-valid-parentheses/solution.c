#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    int n = strlen(s);
    if (n % 2 != 0) return false;  // Odd length can’t be valid

    // Create a stack to store opening brackets
    char* stack = (char*)malloc(n * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        // If it's an opening bracket, push it to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        // If it's a closing bracket, check top of stack
        else {
            if (top == -1) {   // No matching opening bracket
                free(stack);
                return false;
            }

            char topChar = stack[top--];  // Pop from stack

            // Check if it matches the correct type
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                free(stack);
                return false;
            }
        }
    }

    // If stack is empty, it’s valid
    bool valid = (top == -1);
    free(stack);
    return valid;
}


