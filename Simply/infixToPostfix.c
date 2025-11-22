#include <stdio.h>
#include <ctype.h>

int main() {
    char infix[50], stack[50], postfix[50];
    int top = -1, j = 0;
    printf("Enter infix: ");
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) 
            postfix[j++] = c;
        else if (c == '(')
            stack[++top] = c;
        else if (c == ')') {
            while (stack[top] != '(')
                postfix[j++] = stack[top--];
            top--; 
        }
        else { 
            while (top != -1 && (stack[top]=='+'||stack[top]=='-'||
                                stack[top]=='*'||stack[top]=='/'))
                postfix[j++] = stack[top--];
            stack[++top] = c;
        }
    }

    while (top != -1)
        postfix[j++] = stack[top--];

    postfix[j] = '\0';

    printf("Postfix = %s", postfix);
    return 0;
}
