#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//C Program to Implement Singly Linked List Traversal

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* createNode(){
    int val,choice;
    node *start,*temp,*last;
    start = (node*)malloc(sizeof(node));
    if(!start){
        printf("Unavle to allocate Memory..\n");
        return NULL;
    }
    printf("Enter the node value:");
    scanf("%d",&val);
    printf("\n");
    start->data = val;
    start->next = NULL;
    start->prev = NULL;
    last = start;
    printf("Do you want to add more nodes to the list?\nPress 1 for Yes.\nPress 2 for No.\n");
    scanf("%d",&choice);
    while(choice!=2){
        printf("Enter next node value:");
        scanf("%d",&val);
        temp = (node*)malloc(sizeof(node));
        temp->data = val;
        temp->next = NULL;
        temp->prev = last;
        last->next = temp;
        last = last->next;
        printf("Want to add more nodes to the list?\nPress 1 for Yes.\nPress 2 for No.\n");
        fflush(stdin);
        scanf("%d",&choice);

    }
    last->next = NULL;
    return start;
}


void traverse(node* head){
    node* temp = head;
    while(temp->next){
        printf("%d--><--",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
}


int length(node* head){
    int count = 0;
    node* temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}


//We will reverse Linked list thru 3 ways
//1.) Interchanging node position
//2.) Simple reverse Function
//3.)  Reverse by Pointer Swap

node* reverseInterchange(node* head){
    int i,j,len,temp;
    node *p,*q;
    len = length(head);
    p = q = head;
    i = 0;
    j = len-1;
    while(i<j){
        int k=0;
        while(k<j){
            q = q->next;
            k++;
        }
        temp = p->data;
        p->data = q->data;
        q->data = temp;

        i++;j--;
        p = p->next;
        q = head;
    }
    return head;
}


node* reverseSimple(node* head){
    node* curr,*prev = NULL,*nextNode;
    curr = head;
    nextNode = curr->next;
    if(!nextNode){return head;}
    while(nextNode){
        curr->next = prev;
        curr->prev = nextNode;
        prev = curr;
        curr = nextNode;
        nextNode = nextNode->next;
    }
    if(!nextNode){
        curr->next = prev;
    }
    head = curr;
    return head;
}


//reverse by Pointer Swap
node* reverseByPointerSwap(node* head){
    node *current,*rear,*temp,*last;
    int len = length(head);
    int i=0;
    current = head;
    rear = head;
    while(i<len-1){
        rear = rear->next;
        i++;  
    }
    last = rear;
    while(current){
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }
    temp = head;
    head = last;
    last = temp;
    return head;
}


//Driver Function
int main(){
    printf("Implementing Reversal of Doubly Linked list:\n");
    node *first,*reverse_simple,*reverse_interchange,*reverse_pointer_swap;
    int choice;
    first = createNode();
    printf("List after Creation: ");
    traverse(first);
    printf("\n");
    printf("Following Choices are given to you..\n");
    printf("Press 1 for Simple Reversal of Linked List\n");
    printf("Press 2 for Reverse by interchanging nodes.\n");
    printf("Press 3 for Pointer Reversal of Linked List\n");
    printf("Press 4 for Exit.\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    while(choice!=4){
        switch(choice){
            case 1:
            {
                reverse_simple = reverseSimple(first);
                printf("Linked List after reversal is:");
                traverse(reverse_simple);
                printf("\n");
                first = reverseSimple(reverse_simple);
                break;
            }
            case 2:
            {
                reverse_interchange = reverseInterchange(first);
                printf("Linked List after reversal is:");
                traverse(reverse_interchange);
                printf("\n");
                first = reverseInterchange(reverse_interchange);
                break;
            }
            case 3:
            {
                reverse_pointer_swap = reverseByPointerSwap(first);
                printf("Linked List after reversal is:");
                traverse(reverse_pointer_swap);
                printf("\n");
                first = reverseByPointerSwap(reverse_pointer_swap);
                break;
            }
            case 4:{
                exit(0);
            }
            default:{
                printf("Please enter correct option..\n");
                break;
            }
        }
        printf("Enter your choice...");
        scanf("%d",&choice);
        printf("\n");
    }
    return 0;
}