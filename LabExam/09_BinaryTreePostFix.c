#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top=-1;

void push(char c){
    stack[++top]=c;
}
char pop(){
    return stack[top--];
}
struct Node{
    char data;
    struct Node *left,*right;
};
int precedence(char op){
    if(op=='+'||op=='-')return 1;
    if(op=='*'||op=='/')return 2;
    if(op=='^')return 3;
    return 0;
}
int isOperator(char c){
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}
void infixToPostfix(char *infix, char *postfix){
    int i=0,k=0;
    top=-1;
    while(infix[i]){
        char c= infix[i];
        
        if(isalnum(c)){
            postfix[k++]=c;
            i++;
        }
        else if(c=='('){
           push(c);
            i++;
        }
        else if(c==')'){
            while(top!=-1 && stack[top]!='('){
                postfix[k++]=pop();
                postfix[k++]=' ';
            }
            pop();
            i++;
        }
        else if(isOperator(c)){
            while(top!=-1&&stack[top]!='(' && precedence(stack[top])>=precedence(c)&&!(c=='^'&& stack[top]=='^')){
                postfix[k++]=pop();
                postfix[k++]=' ';
            }
        
        push(c);
        i++;
        }
        else{
            i++;
        }
    }
    while(top!=-1){
            postfix[k++]=pop();
            postfix[k++]=' ';
   }
     postfix[k]='\0';
}
//create tree
struct Node* createNode(char c){
    struct Node* node= (struct Node*)malloc(sizeof(struct Node));
    node->data=c;
    node->left=node->right=NULL;
    return node;
}
//build tree
struct Node* buildTree(char *postfix){
    struct Node* stackNode[MAX];
    int topNode=-1;
    
    for(int i=0;postfix[i];i++){
                char c=postfix[i];
        struct Node* node= createNode(c);
        
        if(isalnum(c)){
             stackNode[++topNode]=node;
        }
        if(isOperator(c)){
            node->right=stackNode[topNode--];
            node->left=stackNode[topNode--];
            stackNode[++topNode]=node;
        }
       
    }
 return stackNode[topNode];
}
//show tree
void showTree(struct Node* root,char *prefix,int isLeft){
    if(root==NULL)return;
    
   printf("%s%s%c\n", prefix, (isLeft ? "├──" : "└──"), root->data);
    
    char newprefix[100];
    strcpy(newprefix,prefix);
   strcat(newprefix, (isLeft ? "│   " : "    "));
    
    if (root->left || root->right) {
        showTree(root->left, newprefix, 1);
        showTree(root->right, newprefix, 0);
    }
}
//prinnt tree from expression
void printTree(struct Node* root){
    if(root==NULL)return;
    printTree(root->left);
    printTree(root->right);
    printf("%c",root->data);
}
int main(){
    char infix[MAX],postfix[MAX];
    
    printf("Enter the infix expression:");
    fgets(infix,MAX,stdin);
    
    infixToPostfix(infix,postfix);
    
    struct Node* root= buildTree(postfix);
    printf("\nInfix   : %s", infix);
    printf("\nPostfix : %s", postfix);

    printf("\nPostfix from Tree: ");
    printTree(root);

    printf("\n\nExpression Tree:\n");
    showTree(root, "", 0);

    return 0;
}
