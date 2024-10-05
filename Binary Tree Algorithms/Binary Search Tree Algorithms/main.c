#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node {
    int key;
    struct bst_node* left;
    struct bst_node* right;
} bst_node;

bst_node* create_node(int key) {
    bst_node* new_node = (bst_node*)malloc(sizeof(bst_node));
    new_node->key = key;
    new_node->left = NULL; // securing these pointers from referencing random memory blocks
    new_node->right = NULL;
    return new_node;
}

void insertion(bst_node** root, int key) {
    bst_node* temp = *root;
    if (temp == NULL) {
        bst_node* new_root = create_node(key);
        (*root) = new_root;
        return;
    }
    bst_node* parent = temp;
    while(temp) {
        if(temp->key > key) {
            parent = temp;
            temp = temp->left;
        } else if(temp->key < key) {
            parent = temp;
            temp = temp->right;
        } else {
            // assuming that duplicates aren't allowed in this BST tree
            return;
        }
    }
    bst_node* new_node = create_node(key);
    if(parent->key > key) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
    printf("Insertion of %d is complete.\n", key);
}

void search(bst_node* root, int key) {
    while(root) {
        if(root->key > key) {
            root = root->left;
        } else if(root->key < key) {
            root = root->right;
        } else {
            printf("%d found.\n", key);
            return;
        }
    }
    printf("%d not found.\n", key);
}

void inorder(bst_node* root){
    if(root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

bst_node* successor(bst_node* node) {
    node = node->right;
    while (node != NULL && node->left != NULL) {
        node = node->left;
    }
    return node;
}

bst_node* deletion(bst_node* root, int key, int* flag) {
    if (root == NULL) {
        return root;
    }
    else if(root->key > key) {
        root->left = deletion(root->left, key, flag);
    }
    else if(root->key < key) {
        root->right = deletion(root->right, key, flag);
    }
    else {
        (*flag)=1;
        if(root->left == NULL) {
            bst_node* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL) {
            bst_node* temp = root->left;
            free(root);
            return temp;
        }
        bst_node* succ = successor(root);
        root->key = succ->key;
        root->right = deletion(root->right, succ->key, flag);
        
    }
    return root;
}

int main(){
    bst_node* root=NULL;
    printf("i for insertion\nd for deletion\ns for search\no for inorder display\nq for quitting");
    while(1) {
        char x;
        scanf("%c", &x);
        if(x=='i') {
            int n;
            printf("Enter the key you want to insert: ");
            scanf("%d", &n);
            insertion(&root, n);
        } else if(x=='d') {
            int n;
            printf("Enter the key you want to delete: ");
            scanf("%d", &n);
            int flag=0;
            root = deletion(root, n, &flag);
            if(flag==1) printf("Deletion of %d was successful.\n", n);
            else    printf("Deletion of %d wasn't successful.\n", n);
        } else if(x=='s') {
            int n;
            printf("Enter the key you want to look-up: ");
            scanf("%d", &n);
            search(root, n);

        } else if(x=='o') {
            inorder(root);
            printf("\n");
        } else if(x=='q') {
            printf("Exiting...\n");
        }
    }
    return 0;
}