#include<stdio.h>
#include<stdlib.h>

//Program to implement DoubleLinked List and its
//Basic Operations

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;


node* head; //pointer to head declaration
void insertion_beginning(); //function for inserting at beginning of Linked Lisr
void insertion_last(); //function for inserting node at last
void insertion_specified(); //function for inserting node at particular position
void deletion_beginning(); //function for deleting node from beginning
void deletion_last(); //function for deleting node from last position
void deletion_specified(); //function for deleting node from specified position
void displayLinkedLisr(); //function for displaying double Linked List

void insertion_beginning(){
    node* temp;
    int val;
    temp = (node*)malloc(sizeof(node));
    if(!temp){
        printf("Overflow!");
    }else{
        printf("Enter Value to be Inserted:");
        scanf("%d",&val);

        if(!head){
            temp->next = NULL;
            temp->prev = NULL;
            temp->data = val;
            head = temp;
        }else{
            temp->data = val;
            temp->prev = NULL;
            temp->next  =head;
            head->prev = temp;
            head = temp;
        }
        printf("Node Inserted at Beginning Successfully.\n");
    }
}
void insertion_last(){
    node* ptr,*temp;
    int val;
    ptr = (node*)malloc(sizeof(node));
    if(!ptr){
        printf("Failed to allocate Memory!");
    }else{
        printf("Enter Value to be Inserted:");
        scanf("%d",&val);
        ptr->data = val;
        if(!head){
            ptr->next  =NULL;
            ptr->prev = NULL;
            head = ptr;
        }else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
        printf("Node Inserted Successfully.\n");
    }

}


void insertion_specified(){
    node *ptr,*temp;
    int item,location,i;

    ptr = (node *)malloc(sizeof(node));
    if(!ptr){
        printf("Unable to allocate memory.");
    }else{
        temp = head;
        printf("Enter the location where you want to enter node:");
        scanf("%d",&location);
        printf("\n");
        for(int i=0;i<location;i++){
            temp = temp->next;
            if(!temp){
                printf("Location on which you want to enter is incorrect..\n");
                return;
            }
        }

        printf("Enter value of node:");
        scanf("%d",&item);
        ptr->data = item;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        temp->next->prev = ptr;
        printf("Node Inserted Successfully..");
    }
}

void deletion_beginning(){
    node* ptr;
    if(!head){
        printf("No Head node exists..\n");
    }else if(!head->next){
        free(head);
        printf("Node deleted Successfully.\n");
    }else{
        ptr = head;
        head = head->next;
        head->prev = NULL; 
        free(ptr);
        printf("Node deleted Successfully.\n");
    }
}

void deletion_last_node(){
    node* ptr;
    if(!head){
        printf("No Head node exists..\n");
    }else if(!head->next){
        free(head);
        printf("Node deleted Successfully.\n");
    }else{
        ptr = head;
        while(ptr->next){
            ptr = ptr->next;
        }
        node* temp = ptr->next;
        ptr->next = NULL;
        free(temp);
        printf("Node deleted Successfully.\n");
    }

}

void deletion_specified(){
    node *ptr,*temp;
    int val;
    printf("Enter the node value after which you want to delete the node:");
    scanf("%d",&val);
    printf("\n");
    ptr = head;
    while(ptr->data!=val){
        ptr = ptr->next;
    }

    if(ptr->next==NULL){
        printf("Can't Delete as Limit of Linked List Length Crossed..\n");
    }
    else if(ptr->next->next==NULL){
        node* curr = ptr->next;
        ptr->next  =NULL;
        free(curr);
        printf("Node Deleted Successfully..\n");
    }else{
        temp = ptr->next;
        ptr->next  =temp->next;
        temp->next->prev = ptr;
        free(temp);
        printf("Node Deleted Successfully..\n");
    }
}

//Function to display Double Linked List
void displayLinkedList(){
    node* temp;
    printf("The Double Linked List is:");
    temp=head;
    while(temp->next){
        printf("%d-><-",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
}

//Function to search node in Linked List
void search(){
    printf("Enter the value you want to search in Linked list:");
    int value;
    scanf("%d",&value);
    printf("\n");
    node* temp = head;
    while(temp){
        if(temp->data == value){
            printf("Value is present in the Linked list.\n");
            return;
        }
    }
    printf("Value is not present in the Linked list.\n");
}
//Driver Function
int main(){
   int choice = 0;
   while(choice!=9){
        printf("Main menu for Double Linked List\n");
        printf("Choose One Operation from the following list.\n");
        printf("Press 1 for insert in Beginning\nPress 2 for insert in End\nPress 3 for insert at Random Location\nPress 4 for delete node from beginning\nPress 5 for delete node from end\nPress 6 for delete node from specified Position after a particular data\nPress 7 for search\nPress 8 for displaying Linked List\n Press 9 for exit..\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insertion_beginning();
                break;
            case 2:
                insertion_last();
                break;
            case 3:
                insertion_specified();
                break;
            case 4:
                deletion_beginning();
                break;
            case 5:
                deletion_last_node();
                break;
            case 6:
                deletion_specified();
                break;
            case 7:
                search();
                break;
            case 8:
                displayLinkedList();
                break;
            case 9:
                exit(0);
            default:
                printf("Please Enter valid choice..\n");

        }
   }
   return 0;
}
