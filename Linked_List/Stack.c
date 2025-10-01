/*
Author : Maria 
Date  : Sept 14 2025
Description : Implementation of stack using linked list.
*/

#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node *top;
int count = 0; // to track current number of elements
int maxSize = 0; //to store user input for max number of elements
void display(){
    struct node *ptr;
    if(top==NULL){
        printf("\nStack is empty\n");
    }else{
        ptr=top;
        printf("\nElements are: ");
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
    }
}
void push(int item){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    
    if (count == maxSize) {
    printf("\nStack is FULL!\n");
    free(new); // release unused memory
    return;
    }
  
    new->data=item;
    new->link=top;
    top=new;
    count++;
}
void pop(){
    struct node *temp;
    if(top==NULL){
        printf("\nStack is empty\n");
    }
    else{
        temp=top;
        printf("Popped item is %d\n",top->data);
        top=top->link;
        free(temp);
        count--;
    }
}

void main(){
    int choice,value;;
    printf("Enter the max no of elements in stack: ");
    scanf("%d",&maxSize);

    while(1){
        printf("\n1.PUSH \n2.POP \n3.Exit\nEnter choice: ");
        scanf("%d",&choice);
        
     switch(choice){
         case 1 : printf("Enter the item to push: ");
                  scanf("%d",&value);
                  push(value);
                  display();
                  break;
        case 2  : pop();
                  display();
                  break;
        case 3  : printf("\nExisting program...\n");
                  exit(0);
        default:  printf("\nInvalid Choice\n");
     }
   }
}
