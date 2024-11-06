#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char word[50];
    char meaning[100];
    struct node* left;
    struct node* right;
} node;

node* createNode(char* word, char* meaning){
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

node* insert(node* root, char* word, char* meaning){
    if (root == NULL){
        return createNode(word, meaning);
    }
    else if (strcmp(word, root->word) < 0){
        root->left = insert(root->left, word, meaning);
    }
    else if (strcmp(word, root->word) > 0) {
        root->right = insert(root->right, word, meaning);
    }
    return root;
}

node* findMin(node* root){
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

node* deleteNode(node* root, char* word) {
    if (root == NULL){
        return root;
    }
    else if (strcmp(word, root->word) < 0){
        root->left = deleteNode(root->left, word);
    } 
    else if (strcmp(word, root->word) > 0){
        root->right = deleteNode(root->right, word);
    } 
    else{
        if (root->left == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = findMin(root->right);
        strcpy(root->word, temp->word);
        strcpy(root->meaning, temp->meaning);
        root->right = deleteNode(root->right, temp->word);
    }
    return root;
}

node* mirror(node* root){
    if (root == NULL){
        return NULL;
    }
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    mirror(root->left);
    mirror(root->right);
    
    return root;
}

void levelOrder(node* root){
    if (root == NULL){
        return;
    }
    node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear){
        node* temp = queue[front++];
        printf("%s - %s\n", temp->word, temp->meaning);
        if (temp->left != NULL){
            queue[rear++] = temp->left;
        }
        if (temp->right != NULL){
            queue[rear++] = temp->right;
        }
    }
}

node* copyTree(node* root){
    if (root == NULL){
        return NULL;
    }
    node* newRoot = createNode(root->word, root->meaning);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    
    return newRoot;
}

int main() {
    node* root = NULL;
    int choice;
    char word[50], meaning[100];
    
    do {
        printf("\n1. Insert word\n2. Delete word\n3. Mirror Image\n4. Copy BST\n5. Level Order Traversal\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter word: ");
                scanf("%s", word);
                printf("Enter meaning: ");
                scanf(" %[^\n]", meaning);
                root = insert(root, word, meaning);
                break;
                
            case 2:
                printf("Enter word to delete: ");
                scanf("%s", word);
                root = deleteNode(root, word);
                break;
                
            case 3:
                root = mirror(root);
                printf("Mirror Image Created!\n");
                break;
                
            case 4: {
                node* copy = copyTree(root);
                printf("Copied BST (Level Order):\n");
                levelOrder(copy);
                break;
            }
            
            case 5:
                printf("Level Order Traversal:\n");
                levelOrder(root);
                break;
        }
    } while (choice != 6);
    return 0;
}