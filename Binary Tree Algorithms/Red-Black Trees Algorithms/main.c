
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node* left;
    struct node* right;
    struct node* parent;
    char color;
} Node;

Node* create(int key){
    Node* p=(Node*)malloc(sizeof(Node));
    p->key=key;
    p->left=NULL;
    p->right=NULL;
    p->parent=NULL;
    p->color='r';
    return p;
}

Node* LL(Node* node, Node* root){
    Node* child=node->right;
    node->right=child->left;
    if(node->right){
        node->right->parent=node;
    }
    child->parent=node->parent; 
    if(node->parent==NULL){
        root=child;
    }
    else if(node==node->parent->right){
        node->parent->right=child;
    } else{
        node->parent->left=child;
    }
    child->left=node;
    node->parent=child;
    return child;
}

Node* RR(Node* node, Node* root){
    Node* child=node->left;
    node->left=child->right;
    if(node->left){
        node->left->parent=node;
    }
    child->parent=node->parent; 
    if(node->parent==NULL){
        root=child;
    }
    else if(node==node->parent->left){
        node->parent->left=child;
    } else{
        node->parent->right=child;
    }
    child->right=node;
    node->parent=child;
    return child;
}


Node* RB_fixup(Node* z, Node* root){
    while(z->parent && z->parent->color=='r'){
        if(z->parent->parent && z->parent==(((z->parent)->parent)->left)){
            Node* y=z->parent->right;
            if(y && y->color=='r'){
                z->parent->color='b';
                y->color='b';
                z->parent->parent->color='r';
                z=z->parent->parent;
            } else{
                if(z->parent->right && z==(z->parent->right)){
                    z=z->parent;
                    LL(z, root);
                }
                z->parent->color='b';
                if(z->parent->parent){
                    z->parent->parent->color='r';
                    RR(z->parent->parent, root);
                }
            }
        } else{
            Node* y=z->parent->left;
            if(y && y->color=='r'){
                z->parent->color='b';
                y->color='b';
                z->parent->parent->color='r';
                z=z->parent->parent;
            } else{
                if(z->parent->left && z==(z->parent->left)){
                    z=z->parent;
                    RR(z, root);
                }
                z->parent->color='b';
                if(z->parent->parent){
                    z->parent->parent->color='r';
                    LL(z->parent->parent, root);
                }
            }
        }
    }
    root->color = 'b';
    return root;
}

Node* RB_insert(Node* root, int key){
    Node* p=create(key);
    if(root==NULL) {
        root=p;
    } else {
        Node* t=NULL;
        Node* q=root;
        while(q) {
            t=q;
            if(q->key==key) {
                return root;
            } else if(q->key>key) {
                q=q->left;
            } else {
                q=q->right;
            }
            
        }
        p->parent=t;
        if(t->key>key) {
            t->left=p;
        } else {
            t->right=p;
        }
    }
    root=RB_fixup(p, root);
    return root;
}


void search(Node* root, int key) {
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


void inorder(Node* root){
    if(root){
        inorder(root->left);
        printf("%d %c  ", root->key, root->color);
        inorder(root->right);
    }
}


int main()
{
    Node* root=NULL;
    printf("i for insertion\nd for deletion\ns for search\no for inorder display\nq for quitting");
    while(1) {
        char x;
        scanf("%c", &x);
        if(x=='i') {
            int n;
            printf("Enter the key you want to insert: ");
            scanf("%d", &n);
            root = RB_insert(root, n);
        } else if(x=='d') {
            int n;
            printf("Enter the key you want to delete: ");
            scanf("%d", &n);
            int flag=0;
            //root = deletion(root, n, &flag);
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
