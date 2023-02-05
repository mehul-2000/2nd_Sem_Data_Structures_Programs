#include<stdio.h>
#include<stdlib.h>

struct term {
    int coefficient;
    int degree;
    struct term *next;
};

struct term *createTerm(int coefficient, int degree) {
    struct term *newTerm = (struct term*) malloc(sizeof(struct term));
    newTerm->coefficient = coefficient;
    newTerm->degree = degree;
    newTerm->next = NULL;
    return newTerm;
}

struct term *addPolynomials(struct term *poly1, struct term *poly2) {
    struct term *result = NULL;
    struct term *tail = NULL;
    struct term *temp1 = poly1, *temp2 = poly2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->degree > temp2->degree) {
            if (result == NULL) {
                result = tail = temp1;
            } else {
                tail->next = temp1;
                tail = temp1;
            }
            temp1 = temp1->next;
        } else if (temp2->degree > temp1->degree) {
            if (result == NULL) {
                result = tail = temp2;
            } else {
                tail->next = temp2;
                tail = temp2;
            }
            temp2 = temp2->next;
        } else {
            int coefficient = temp1->coefficient + temp2->coefficient;
            if (coefficient) {
                if (result == NULL) {
                    result = tail = createTerm(coefficient, temp1->degree);
                } else {
                    tail->next = createTerm(coefficient, temp1->degree);
                    tail = tail->next;
                }
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL) {
        tail->next = temp1;
        tail = temp1;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        tail->next = temp2;
        tail = temp2;
        temp2 = temp2->next;
    }
    return result;
}

void printPolynomial(struct term *poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->degree);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
}


int main() {
    struct term *poly1 = createTerm(5, 3);
    poly1->next = createTerm(4, 2);
    poly1->next->next = createTerm(2, 0);
    struct term *poly2 = createTerm(5, 2);
    poly2->next = createTerm(3, 0);
    struct term *result = addPolynomials(poly1, poly2);
    printf("First polynomial: ");
    printPolynomial(poly1);
    printf("\n");
    printf("Second polynomial: ");
    printPolynomial(poly2);
    printf("\n");
    printf("Resultant Polynomial: ");
    printPolynomial(result);
    return 0;

}