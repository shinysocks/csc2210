#include "stdio.h"
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int coefficient;
    int power;
    struct Node *next;
} Node;

Node* add_polynomials(Node*, Node*);
Node* create_node(int coefficient, int exponent);
void display_polynomial(Node *node);

int main() {
    Node* first = create_node(3, 1);
    first->next = create_node(4, 2);
    first->next->next = create_node(-6, 3);

    Node* second = create_node(4, 1);
    second->next = create_node(-10, 2);
    second->next->next = create_node(8, 3);

    Node *sum = add_polynomials(first, second);

    display_polynomial(first);
    printf(" +\n");
    display_polynomial(second);
    printf("--------------------------------------------------\n");
    display_polynomial(sum);

    return 0;
}

Node* create_node(int coefficient, int exponent) {
    Node *n = (Node*) malloc(sizeof(Node));
    n->power = exponent;
    n->coefficient = coefficient;
    n->next = NULL;
    return n;
}

void display_polynomial(Node* n) {
    Node *temp = n;
    while (temp != NULL) {
        printf(" %dx%d", temp->coefficient, temp->power);
        temp = temp->next;
    }
    printf("\n");
}

Node* add_polynomials(Node *n1, Node *n2) {
    Node *temp1 = n1;
    Node *temp2 = n2;

    Node *sum = create_node(temp1->coefficient + temp2->coefficient, temp1->power);

    temp1 = temp1->next;
    temp2 = temp2->next;

    Node *result = sum;

    while (temp1 != NULL) {
        result->next = create_node(temp1->coefficient + temp2->coefficient, temp1->power);

        result = result->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return sum;
}
