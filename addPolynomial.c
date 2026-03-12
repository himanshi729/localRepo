#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int coeff, exp;
    struct Node* next;
};
// Creat memory for node

struct Node* createNode(int coeff, int exp){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> coeff = coeff;
    newNode -> exp = exp;
    newNode -> next = NULL;
    return newNode;
}
// Insert Node

struct Node* insertNode(struct Node* head, int coeff, int exp){
    struct Node* newNode = createNode(coeff, exp);

    if(head == NULL)
        return newNode;
    struct Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    } 
    temp -> next = newNode;
        return head;   
    
}
// Adding polynomial

struct Node* addPoly(struct Node* poly1, struct Node* poly2){
    struct Node* result = NULL;

    while(poly1 != NULL && poly2 != NULL){
        if(poly1 -> exp == poly2 -> exp){
            result = insertNode(result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1 -> next;
            poly2 = poly2 -> next;
        }
        else if(poly1->exp > poly2->exp){
            result = insertNode(result, poly1->coeff , poly1->exp);
            poly1 = poly1->next;
        }
        else{
            result = insertNode(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }

    while(poly1 != NULL){
        result = insertNode(result, poly1->coeff, poly1->exp);
        poly1 = poly1-> next;
    }
    while(poly2 != NULL){
        result = insertNode(result, poly2->coeff, poly2->exp);
        poly2 = poly2-> next;
    }

    return result;
}
void display(struct Node* head){
    while(head != NULL){
        printf("%dx^%d", head->coeff, head->exp);
        if(head-> next != NULL)
            printf("+");
            head = head -> next;
        }
        printf("\n");
    
}

int main(){
    struct Node* p1 = NULL;
    struct Node* p2 = NULL;
    struct Node* result = NULL;

    int n, coeff, exp;

    printf("Enter number of terms in 1st polynomial:\n");
    scanf("%d", &n);

    printf("Enter coefficient and exponent of the polynomial: \n");
    for(int i=0; i<n; i++){
        scanf("%d %d", &coeff, &exp);
        p1 =  insertNode(p1, coeff, exp);
    }

    printf("Enter number of terms in 2nd polynomial: \n");
    scanf("%d", &n);

    printf("Enter coefficient and exponent of the 2nd Polynomial: \n");
    for(int i=0; i<n; i++){
        scanf("%d %d", &coeff, &exp);
        p2 = insertNode(p2, coeff, exp);
    }

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("\nSecond Polynomial: ");
    display(p2);

    result = addPoly(p1, p2);

    printf("\nResultant Polynomial: ");
    display(result);

    return 0;
}