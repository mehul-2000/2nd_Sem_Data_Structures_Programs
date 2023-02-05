#include<stdio.h>
#include<stdlib.h>

//Program to implement Single Linked List and its
//Basic Operations

typedef struct node{
    int data;
    struct node* link;
}node;

//Function to create Linked List 
node* createLinkedList(){
    int val;
    int ch;
    node *head,*temp,*last;

    head = (node*)malloc(sizeof(node));
    printf("Enter the Node: ");
    scanf("%d",&val);

    head->data = val;
    last = head;
    printf("Do you want to add more? ");
    scanf("%d",&ch);
    while(ch!=2){
        printf("Enter next value to be inserted into Linked List: ");
        scanf("%d",&val);
        temp = (node*)malloc(sizeof(node));
        temp->data = val;
        last->link = temp;
        last = last->link;
        printf("Want to add more Data?: ");
        fflush(stdin);
        scanf("%d",&ch);
    }
    last->link = NULL;
    return head;
}


//Function to Traverse Linked list
void traverseLinkedList(node* head){
    node* temp;
    temp = head;
    while(temp->link){
        printf("%d-->",(temp->data));
        temp = temp->link;
    }
    printf("%d",(temp->data));
}


//Function to find Length of Linked List
int lengthOfLinkedList(node* head){
    int cnt= 0;
    node* temp;
    temp = head;
    while(temp){
        cnt++;
        temp = temp->link;
    }
    return cnt;
}


//Function to Insert Node in a Linked List
node* insertNode(node* head){
    node* temp,*prev;
    int pos,len,val,count=0;
    len = lengthOfLinkedList(head);
    printf("Enter the Position at which you want to add the Node:");
    scanf("%d",&pos);
    printf("\n");
    if(pos<=len+1){
        printf("Enter the Node Value:");
        scanf("%d",&val);
        temp = (node*)malloc(sizeof(node));
        temp->data = val;
        temp->link = NULL;
        if(pos==1){
            temp->link = head;
            head = temp;
        }else{
            prev = head;
            while(prev->link!=NULL && count<pos-2){
                prev = prev->link;
                count++;
            }
            temp->link = prev->link;
            prev->link = temp;
        }
        return head;
    }else{
        printf("Not a Valid Position\n");
    }
}



//Function to delete a Node from Linked List from specific
//Position 
node* deleteNode(node* head){
    int pos,len,count=0;
    len = lengthOfLinkedList(head);
    printf("Enter the Position at which you want to delete the Node:");
    scanf("%d",&pos);
    printf("\n");
    if(pos<=len){
        node* temp;
        temp = head;
        if(pos==1){
            head = temp->link;
            free(head);
        }else{
            while(temp->link && count<pos-2){
                temp = temp->link;
                count++;
            }

            if(!temp->link){
                printf("Invalid Posiiton Entered.");
            }else{
                node* freeze;
                freeze = temp->link;
                temp->link = temp->link->link;
                free(freeze);
            }
        }
    }else{
        printf("Not a Valid Position to be deleted.\n");
    }
    return head;
}

//Driver Function
int main(){
   printf("Implementing Linked List:\n");
   node* head,*newHead;
   int len,choice;
   head = createLinkedList();
   printf("The Created Linked List is:");
   traverseLinkedList(head);
   printf("\n");
   len = lengthOfLinkedList(head);

   printf("The Length of the created Linked list is %d\n",len);
   prinf("Whether you want to perform more operations?\nPress 1 For addition of Node\nPress 2 for deletion of node\nPress 3 for traversal of Linked List\nPress 4 for Exit..\n");
   scanf("%d",&choice);
   while(choice!=4){
        if(choice==1){
            newHead = insertNode(head);
            traverse(newHead);
        }else if(choice==2){
            newHead = deleteNode(head);
            traverse(newHead);
        }else if(choice==3){
            traverse(newHead);
        }

        prinf("Whether you want to perform more operations?\nPress 1 For addition of Node\nPress 2 for deletion of node\nPress 3 for traversal of Linked List\nPress 4 for Exit..\n");
        scanf("%d",&choice);

   }
   return 0;
}
