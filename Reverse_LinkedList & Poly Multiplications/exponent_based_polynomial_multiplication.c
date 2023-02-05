#include<stdio.h>
#include<stdlib.h>

//C Program to Implement exponent based Linked List Polynomial Multiplication

typedef struct node{
    int coeff,expo;
    struct node *link;
}node;

node* createLinkedList(){
    int val,choice;
    node *start,*temp,*last;
    start = (node*)malloc(sizeof(node));
    if(!start){
        printf("Unable to allocate Memory..\n");
        return NULL;
    }
    printf("Enter the node Coefficient:");
    scanf("%d",&start->coeff);
    printf("\n");
    printf("Enter the node Exponent:");
    scanf("%d",&start->expo);
    printf("\n");
    last = start;
    printf("Do you want to add more nodes to the list?\nPress 1 for Yes.\nPress 2 for No.\n");
    scanf("%d",&choice);
    while(choice!=2){
        temp = (node*)malloc(sizeof(node));
        printf("Enter the node Coefficient:");
        scanf("%d",&temp->coeff);
        printf("\n");
        printf("Enter the node Exponent:");
        scanf("%d",&temp->expo);
        temp->link = NULL;
        last->link = temp;
        last = last->link;
        printf("Want to add more nodes to the list?\nPress 1 for Yes.\nPress 2 for No.\n");
        fflush(stdin);
        scanf("%d",&choice);

    }
    last->link = NULL;
    return start;
}

void traverse(node* head){
    node* temp = head;
    if(!head){
        printf("Polynomial is Empty..\n");
    }else{
        while(temp){
            if(temp->expo){
                printf("%dx^(%d)",temp->coeff,temp->expo);
            }else{
                printf("%d",temp->coeff);
            }

            if(temp->link){
                if(temp->link->coeff){
                    printf("+");
                }
            }
            temp = temp->link;
        }
    }
}


node* add_poly_expo(node* poly1,node* poly2){
    node* poly3,*last,*temp;
    poly3 = NULL;
    if(!poly1 && !poly2){
        return poly3;
    }

    while(poly1 && poly2){
        if(poly1->expo == poly2->expo){
            if(poly1->expo + poly2->expo!=0){
                temp = (node*)malloc(sizeof(node));
                if(temp){
                    temp->coeff = poly1->coeff + poly2->coeff;
                    temp->expo = poly1->expo;
                    temp->link = NULL; 
                    if(!poly3){
                        poly3 = temp;
                        last = poly3;
                    }else{
                        last->link = temp;
                        last = temp;
                    }
                }else{
                    printf("Unable to allocate Memory.\n");
                }
            }
            poly1 = poly1->link;
            poly2 = poly2->link;
        }else if(poly1->expo>poly2->expo){
            temp = (node*)malloc(sizeof(node));
            if(temp){
                temp->coeff = poly1->coeff;
                temp->expo = poly1->expo;
                temp->link = NULL;
                if(!poly3){
                    poly3 = temp;
                    last = poly3;
                }else{
                    last->link = temp;
                    last = temp;
                }
                poly1 = poly1->link;
            }else{
                printf("Unable to allocate Memory.\n");
            }
        }else{
            temp = (node*)malloc(sizeof(node));
            if(temp){
                temp->coeff = poly2->coeff;
                temp->expo = poly2->expo;
                temp->link = NULL;
                if(!poly3){
                    poly3 = temp;
                    last = poly3;
                }else{
                    last->link = temp;
                    last = temp;
                }
                poly2 = poly2->link;
            }else{
                printf("Unable to allocate Memory.\n");
            }
        }
    }

    while(poly1){
        temp = (node*)malloc(sizeof(node));
        if(temp){
            temp->coeff = poly1->coeff;
            temp->expo = poly1->expo;
            temp->link = NULL;
            if(!poly3){
                poly3 = temp;
                last = poly3;
            }else{
                last->link = temp;
                last = temp;
            }
            poly1 = poly1->link;
        }else{
            printf("Unable to allocate Memory.\n");
        }
    }
    while(poly2){
        temp = (node*)malloc(sizeof(node));
        if(temp){
            temp->coeff = poly2->coeff;
            temp->expo = poly2->expo;
            temp->link = NULL;
            if(!poly3){
                poly3 = temp;
                last = poly3;
            }else{
                last->link = temp;
                last = temp;
            }
            poly2 = poly2->link;
        }else{
            printf("Unable to allocate Memory.\n");
        } 
    }
    return poly3;
}


node* multiply_first_term(int coeff,int expo,node* poly){
    node* poly1 = NULL,*last = NULL;
    while(poly){
        node* temp = (node*)malloc(sizeof(node));
        temp->coeff = coeff * (poly->coeff);
        temp->expo = (poly->expo) + expo;
        if(!poly1){
            poly1 = temp;
            last = temp;
        }else{
            last->link = temp;
            last = temp;
        }
        last->link = NULL;
        poly = poly->link;
    }
    return poly1;
}

node* multiply(node* poly1,node* poly2){
    node* poly3 = NULL,*poly;
    node* temp1 = poly1,*temp2 = poly2;
    while(temp1){
        poly = multiply_first_term(temp1->coeff,temp1->expo,poly2);
        poly3 = add_poly_expo(poly3,poly); 
        free(poly);
        temp1 = temp1->link;
    }
    return poly3;
}


int main(){
    node *poly1,*poly2,*poly3;
    printf("For Polynomial 1: ");
    poly1 = createLinkedList();
    printf("\n");
    printf("For Polynomial 2: ");
    poly2 = createLinkedList();
    printf("\n[ ");
    traverse(poly1);
    printf(" ] * [ ");
    traverse(poly2);
    printf(" ] = [ ");
    poly3 = multiply(poly1,poly2);
    traverse(poly3);
    printf(" ]");
    return 0;
}