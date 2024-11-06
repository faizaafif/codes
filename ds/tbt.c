#include <stdio.h>
#include <stdlib.h>

typedef struct tbtnode {
    int data;
    struct tbtnode *leftc, *rightc;
    int lbit, rbit;
} tbtnode;

tbtnode* createNode(int data) {
    tbtnode* newNode = (tbtnode*)malloc(sizeof(tbtnode));
    newNode->data = data;
    newNode->leftc = NULL;
    newNode->rightc = NULL;
    newNode->lbit = 0;
    newNode->rbit = 0;
    return newNode;
}

void createTBT(tbtnode *head) {
    tbtnode *root = NULL, *temp, *curr;
    int data, flag, choice;
    char cont = 'y';

    printf("Enter root data: ");
    scanf("%d", &data);
    root = createNode(data);
    head->lbit = 1;
    root->leftc = root->rightc = head;
    head->leftc = root;

    do {
        flag = 0;
        temp = root;

        printf("Enter data for new node: ");
        scanf("%d", &data);
        curr = createNode(data);

        while (flag == 0) {
            printf("Enter 1 to insert left or 2 to insert right: ");
            scanf("%d", &choice);

            if (choice == 1) {
                if (temp->lbit == 0) {
                    curr->rightc = temp;
                    curr->leftc = temp->leftc;
                    temp->leftc = curr;
                    temp->lbit = 1;
                    flag = 1;
                } else {
                    temp = temp->leftc;
                }
            } else if (choice == 2) {
                if (temp->rbit == 0) {
                    curr->leftc = temp;
                    curr->rightc = temp->rightc;
                    temp->rightc = curr;
                    temp->rbit = 1;
                    flag = 1;
                } else {
                    temp = temp->rightc;
                }
            }
        }
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &cont);
    } while (cont == 'y');
}

void inorderTraversal(tbtnode *head) {
    tbtnode *temp = head->leftc;

    while (temp != head) {
        while (temp->lbit == 1)
            temp = temp->leftc;

        printf("%d ", temp->data);

        while (temp->rbit == 0 && temp->rightc != head) {
            temp = temp->rightc;
            printf("%d ", temp->data);
        }
        temp = temp->rightc;
    }
}

int main() {
    tbtnode *head = createNode(-1);
    head->leftc = head;
    head->rightc = head;
    head->lbit = 0;
    head->rbit = 1;

    createTBT(head);

    printf("\nIn-order Traversal of Threaded Binary Tree:\n");
    inorderTraversal(head);

    return 0;
}