#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left ,*right;
};

struct Node* createNode(char c){
    struct Node* temp=malloc(sizeof(struct Node));
    temp->data=c;
    temp->left=temp->right=NULL;
    return temp;
}
void preorder(struct Node*root){
    if(root!=NULL){
        printf("%c",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    struct Node* root= createNode('+');
    root->left=createNode('a');
    root->right=createNode('b');
    printf("Prefix Expression: ");
    preorder(root);
    return 0;
    
}
