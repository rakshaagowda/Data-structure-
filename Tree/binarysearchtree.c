#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct node {
    int key;
    struct node *left, *right;
};
typedef struct node* NODE;

// Function to create a new node
NODE createNode(int key) {
    NODE newnode = (NODE)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Function to insert a node into BST
NODE insert(NODE root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Preorder traversal (Root, Left, Right)
void preOrder(NODE root) {
    if (root) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Inorder traversal (Left, Root, Right)
void inOrder(NODE root) {
    if (root) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postOrder(NODE root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

// Function to search for a node and return its parent
NODE search(NODE root, int key, NODE* parent) {
    NODE current = root;
    *parent = NULL;

    while (current != NULL && current->key != key) {
        *parent = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }
    return current;
}

// Function to count the total number of nodes in BST
int countNodes(NODE root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to find height of BST
int findHeight(NODE root) {
    if (root == NULL)
        return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to find the maximum node and its parent
NODE findMaxParent(NODE root, NODE* parent) {
    *parent = NULL;
    if (root == NULL)
        return NULL;

    NODE current = root;
    while (current->right != NULL) {
        *parent = current;
        current = current->right;
    }
    return current;
}

// Menu-driven function
int main() {
    NODE root = NULL;
    NODE parent = NULL;
    int choice, key;
    
    while (1) {
        printf("\n==== Binary Search Tree Menu ====\n");
        printf("1. Insert a node\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search for a node\n");
        printf("6. Count total nodes\n");
        printf("7. Find height of BST\n");
        printf("8. Find maximum node and its parent\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Node inserted.\n");
                break;

            case 2:
                printf("Preorder Traversal: ");
                preOrder(root);
                printf("\n");
                break;

            case 3:
                printf("Inorder Traversal: ");
                inOrder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postOrder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter key to search: ");
                scanf("%d", &key);
                NODE snode = search(root, key, &parent);
                if (snode != NULL) {
                    printf("Node %d found.\n", snode->key);
                    if (parent != NULL) {
                        printf("Parent Node: %d\n", parent->key);
                    } else {
                        printf("The node is the root (No parent).\n");
                    }
                } else {
                    printf("Key not found.\n");
                }
                break;

            case 6:
                printf("Total number of nodes: %d\n", countNodes(root));
                break;

            case 7:
                printf("Height of BST: %d\n", findHeight(root));
                break;

            case 8:
                NODE maxnode = findMaxParent(root, &parent);
                if (maxnode != NULL) {
                    printf("Maximum Node: %d\n", maxnode->key);
                    if (parent != NULL) {
                        printf("Parent Node: %d\n", parent->key);
                    } else {
                        printf("The node is the root (No parent).\n");
                    }
                } else {
                    printf("BST is empty.\n");
                }
                break;

            case 9:
                printf("Exiting program.\n");
                return;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Main function

