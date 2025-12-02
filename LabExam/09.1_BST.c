//binary search tree without using switch case
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int value){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;
}
struct Node *insertNode(struct Node* root, int value){
    if(root==NULL){
        return createNode(value);
    }
    if(value<root->data){
        root->left=insertNode(root->left,value);
    }else if(value>root->data){
        root->right=insertNode(root->right,value);
    }
    return root;
}
struct Node* searchNode(struct Node* root,int value){
    if(root==NULL ||root->data==value){
        return  root;
    }
    if(value<root->data){
        return searchNode(root->left,value);
    }else{
        return searchNode(root->right,value);
    }
}
struct Node* findMin(struct Node* root){
    while(root->left!=NULL)
        root=root->left;
    return root;
}
struct Node* deleteNode(struct Node* root,int value){
    if(root==NULL){
        return root;
    }else if(value<root->data){
        root->left=deleteNode(root->left,value);
    }else if(value>root->data){
        root->right=deleteNode(root->right,value);
    }else{
        if(root->left==NULL){
            struct Node* temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL){
            struct Node* temp=root->left;
            free(root);
            return temp;
        }
    
    //tree having two children
    struct Node* temp= findMin(root->right);
    root->data=temp->data;
    root->right=deleteNode(root->right,temp->data);
    }
    return root;
}
void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main(){
    int choice, value;
    struct Node* root=NULL;
    while(1){
        printf("1.Insert\n2.Delete\n3.Search\n4.Exit\nEnter the Choice: \n");
        scanf("%d",&choice);
        
        if(choice==1){
            printf("Enter the vlaue to insert: ");
            scanf("%d",&value);
            root= insertNode(root,value);
            printf("Tree :");
            inorder(root);
            printf("\n");
          
        }
        else if(choice==2){
            printf("enter the value to delete: ");
            scanf("%d",& value);
            if(searchNode(root,value)==NULL){
                printf("No such value present\n");
            }else{
               root= deleteNode(root,value);
               printf("\nDeleted");
            }
             printf("Tree :");
            inorder(root);
            printf("\n");
           
        }
        else if(choice==3){
            printf("enter the value to value: ");
            scanf("%d",& value);
            if(searchNode(root,value)!=NULL){
                printf("Found\n");
            }else{
                printf("Not Found..");
            }
             printf("Tree :");
            inorder(root);
            printf("\n");
           
        }
        else if(choice==4){
            printf("\nExiting...");
            return 0;
        }else{
            printf("\nInvalid choice \n");
        }
    }
    return 0;
}
