/*
Author : Maria
Date : Sept 14 2025
Description : Implementation of queue using linked list
 */
  
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *front=NULL,*rear=NULL;
/*if we didn't use count and maxsize and only use n in the main function , we can insert and delete the values unlimited time(they are not able to consider the n value when function calls in linked list)
*/
int count = 0; // to track current number of elements
int maxSize = 0; //to store user input for max number of elements
//function to display the queue
void display(){
    struct node *ptr;
    if(front==NULL){
        printf("Queue is Empty");
    }
    else{
        ptr=front;
        printf("\n Queue elements are: ");
        while(ptr!=NULL){
           printf("%d\t",ptr->data);
           ptr=ptr->link;
        }
    }
}
void enqueue(int item){
    if (count == maxSize) {  //check max size before inserting
        printf("\nQueue is FULL! Cannot insert %d\n", item);
        return;
    }
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    if (new == NULL) { 
        printf("\nQueue is FULL! Cannot insert\n");
        return;
    }
    new->data=item;
    new->link=NULL;
    if(front==NULL){
        front=rear=new;
    }
    else{
        rear->link=new;
        rear=new;
    }
    count++;
    
}
void dequeue(){
    struct node *temp;
    if(front==NULL){//queue is empty
        printf("\nQueue is empty\n");
    }
    else if(front==rear){//queue has only 1 element
        temp=front;
        front=rear=NULL;
        free(temp);//releasing the memory of temp
        count--;
        printf("\nQueue is now EMPTY.\n");
    }
    else{//contains more than 1 elements 
        temp=front;
        front=front->link;
        free(temp);//releasing the memory of temp
        count--;
    }
}
void main(){
    int choice,value;;
    printf("Enter the max no of elements in queue: ");
    scanf("%d",&maxSize);
    
    while(1){
        printf("\n1.Enqueue \n2.Dequeue \n3.Exit\nEnter choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: printf("Enter the value to insert at rear: ");
                    scanf("%d",&value);
                    enqueue(value);
                    display();
                    break;
            case 2: dequeue();
                    display();
                    break;
            case 3: 
                    printf("Existing program");
                    exit(0);
            default:
                    printf("Invalid Choice");
            
        }
    }
}
