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

Node* RB_delete(Node* root, int key) {
    
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        printf("%d %c  ", root->key, root->color);
        inorder(root->right);
    }
}

void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d %c  ", root->key, root->color);
    }
}

int main()
{
    Node* root=NULL;
    root=RB_insert(root, 41);
    root=RB_insert(root, 38);
    root=RB_insert(root, 31);
    root=RB_insert(root, 12);
    root=RB_insert(root, 19);
    root=RB_insert(root, 8);
    inorder(root);
    printf("\n");
    postorder(root);

    return 0;
}
