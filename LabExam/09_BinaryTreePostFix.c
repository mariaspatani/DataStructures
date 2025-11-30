#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// ----------- STACK FOR INFIX→POSTFIX -----------
char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

// ----------- NODE STRUCTURE FOR TREE -----------
struct Node {
    char data;
    struct Node *left, *right;
};

// ----------- PRECEDENCE CHECK -----------
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

// ----------- INFIX → POSTFIX -----------
void infixToPostfix(char *infix, char *postfix) {
    int i = 0, k = 0;
    top = -1;
    
    while (infix[i]) {
        char c = infix[i];

        if (isspace(c)) { i++; continue; }

        if (isalnum(c)) {
            postfix[k++] = c;
            i++;
        }
        else if (c == '(') {
            push(c);
            i++;
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop(); 
            i++;
        }
        else if (isOperator(c)) {
            while (top != -1 && stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(c) &&
                   !(c=='^' && stack[top]=='^')) {
                postfix[k++] = pop();
            }
            push(c);
            i++;
        }
        else {
            i++;
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

// ----------- CREATE TREE NODE -----------
struct Node* createNode(char c) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = c;
    node->left = node->right = NULL;
    return node;
}

// ----------- BUILD EXPRESSION TREE FROM POSTFIX -----------
struct Node* buildTree(char *postfix) {
    struct Node* stackNode[MAX];
    int topNode = -1;

    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];

        struct Node* node = createNode(c);

        if (isalnum(c)) {
            stackNode[++topNode] = node;
        }
        else if (isOperator(c)) {
            node->right = stackNode[topNode--];
            node->left  = stackNode[topNode--];
            stackNode[++topNode] = node;
        }
    }
    return stackNode[topNode];
}

// ----------- PRINT TREE (ASCII FORMAT) -----------
void showTree(struct Node* root, char *prefix, int isLeft) {
    if (root == NULL) return;

    printf("%s%s%c\n", prefix, (isLeft ? "├──" : "└──"), root->data);

    char newPrefix[100];
    strcpy(newPrefix, prefix);
    strcat(newPrefix, (isLeft ? "│   " : "    "));

    if (root->left || root->right) {
        showTree(root->left, newPrefix, 1);
        showTree(root->right, newPrefix, 0);
    }
}

// ----------- PRINT POSTFIX FROM TREE -----------
void printPostfixFromTree(struct Node* root) {
    if (root == NULL) return;
    printPostfixFromTree(root->left);
    printPostfixFromTree(root->right);
    printf("%c", root->data);
}

// ----------- MAIN -----------
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0;

    // Convert to postfix
    infixToPostfix(infix, postfix);

    // Build tree
    struct Node* root = buildTree(postfix);

    printf("\nInfix   : %s", infix);
    printf("\nPostfix : %s", postfix);

    printf("\nPostfix from Tree: ");
    printPostfixFromTree(root);

    printf("\n\nExpression Tree:\n");
    showTree(root, "", 0);

    return 0;
}
