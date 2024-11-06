#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 
struct node {
   
    char name[50];
    int prn;
    char desig[50];
    struct node *next;
};

int count = 0;

void create(struct node *head);
void display(struct node *head);
int length(struct node *head);
void insert(struct node *head, int position);
void delete(struct node *head, int position);  
void reverse(struct node *head);  
void sort(struct node *head);

int main() {
    int choice, position;
    struct node *head;
    head = (struct node *) malloc(sizeof(struct node));
   
    head->name[0] = '\0';
    head->prn = 0;
    head->desig[0] = '\0';
    head->next = NULL;

    while (1) {
        printf("\nChoose the option: \n1. Create \n2. Display \n3. Insert by position \n4. Delete by position \n5. Reverse list\n6. Sort By PRN\n7. Exit\n");
        scanf("%d", &choice);
     
        switch (choice) {
            case 1:
                create(head);
                break;

            case 2:
                display(head);
                break;

            case 3:
                printf("Enter the position to insert the node: ");
                scanf("%d", &position);
                insert(head, position);
                break;

            case 4:
                printf("Enter the position to delete the node: ");
                scanf("%d", &position);
                delete(head, position);  
                break; 
            
            case 5:
                reverse(head);  
                break;
                
            case 6:
                sort(head);  
                break;

            case 7:
                exit(0);

            default:
                printf("Enter a valid option\n");
                break;
        }
    }
}


void create(struct node *head) {
    char ch;
    struct node *temp = head;
    struct node *curr;

    printf("Do you want to add data? (y/n): ");
    scanf(" %c", &ch);
    while (ch == 'Y' || ch == 'y') {
        curr = (struct node *) malloc(sizeof(struct node));
        if (curr == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter the Name: ");
        scanf("%s", curr->name);
        printf("Enter the PRN: ");
        scanf("%d", &curr->prn);
        printf("Enter the Designation: ");
        scanf("%s", curr->desig);

        curr->next = NULL;

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = curr;

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &ch);
    }
}

void display(struct node *head) {
    struct node *temp = head->next;
   
    if (temp != NULL) {
        while (temp != NULL) {
            printf("%s | ", temp->name);
            printf("%d | ", temp->prn);
            printf("%s | ", temp->desig);
            printf("%p -> ", (void *)temp);
            temp = temp->next;
            count++;
        }
        printf("NULL\n");
        printf("\nLength of linked list: %d", count);
    } else {
        printf("Linked list is empty\n");
    }
    count = 0;  // Reset count after display
}

void insert(struct node *head, int position) {
    int len = length(head);
    if (position <= len + 1) {
        struct node *temp = head;
        struct node *newnode;
        int count = 1;

        while (count < position) {
            temp = temp->next;
            count++;
        }

        newnode = (struct node *) malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter the Name: ");
        scanf("%s", newnode->name);
        printf("Enter the PRN: ");
        scanf("%d", &newnode->prn);
        printf("Enter the Designation: ");
        scanf("%s", newnode->desig);

        newnode->next = temp->next;
        temp->next = newnode;
        printf("Node inserted at position %d.\n", position);
    } else {
        printf("Enter correct position (should be <= length + 1).\n");
    }
}

int length(struct node *head) {
    int len = 0;
    struct node *temp = head->next;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void delete(struct node *head, int position) {  
    int len = length(head);
   
    if (position <= len && position > 0) {
        struct node *temp = head;
        struct node *curr;
        int count = 1;

        while (count < position) {
            temp = temp->next;
            count++;
        }

        curr = temp->next;
        if (curr == NULL) {
            printf("No node to delete at this position.\n");
            return;
        }

        temp->next = curr->next;
        curr->next = NULL;
        free(curr);

        printf("Node at position %d deleted.\n", position);
    } else {
        printf("Enter a valid position (1 to %d).\n", len);
    }
}

void reverse(struct node *head) {
    struct node *last = NULL;      
    struct node *curr = head->next; 
    struct node *future;    

    while (curr != NULL) {
        future = curr->next;   
        curr->next = last;    
        last = curr;          
        curr = future;         
    }

    head->next = last;        
    printf("List Reversed.\n");
}

void sort(struct node *head) {
 int len = 0;
    struct node *temp = head;
    struct node *curr1, *curr2, *prev;
    

    while (temp->next != NULL) {
        len++;
        temp = temp->next;
    }
    
    for (int i = 0; i < len - 1; i++) {
        temp = head;         
        curr1 = head->next;  
        curr2 = curr1->next; 

        for (int j = 0; j < len - 1; j++) {
            if (curr2 != NULL && curr1->prn > curr2->prn) {
                
                curr1 -> next = curr2->next;  
                curr2 -> next = curr1;
                temp -> next = curr2;
                
                temp = curr2;
            } else {              
                temp = curr1;
                curr1 = curr2;
            }
            curr2 = curr1->next;
        }
    }
    printf("Linked list sorted by PRN.\n");
}
