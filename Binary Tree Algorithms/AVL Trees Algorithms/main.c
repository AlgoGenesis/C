#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct treeNode{
    int key;
    struct treeNode* left;
    struct treeNode* right;
    int height;
} Node;

Node* create(int key){
    Node* p=(Node*)malloc(sizeof(Node));
    p->key=key;
    p->height=1;
    p->left=NULL;
    p->right=NULL;
    return p;
}

int max(int a, int b){
    return a > b ? a : b;
}

int height(Node* root){
    if(root==NULL)  return 0;
    else {
        int left=height(root->left);
        int right=height(root->right);
        return max(left, right) + 1;
    }
}

int get_bf(Node* root){
    if(root==NULL)  return 0;
    return height(root->left) - height(root->right);
}

Node* LL(Node* node){
    Node* child=node->right;
    node->right=child->left;
    child->left=node;
    node->height=max(height(node->right), height(node->left))+1;
    child->height=max(height(child->right), height(child->left))+1;
    return child;
}

Node* RR(Node* node){
    Node* child=node->left;
    node->left=child->right;
    child->right=node;
    node->height=max(height(node->right), height(node->left))+1;
    child->height=max(height(child->right), height(child->left))+1;
    return child;
}

Node* AVL_insert(Node* root, int key){
        if(root==NULL){
            return create(key);
        }
        if(key < root->key){
            root->left=AVL_insert(root->left, key);
        }
        else if(key > root->key){
            root->right=AVL_insert(root->right, key);
        }
        else{
            return root;
        }
        root->height=max(height(root->right), height(root->left)) + 1;
        int bf=get_bf(root);
        //trace a path upwards recursively
        //left heavy
        if(bf>1){
            //perform rotations
            if(get_bf(root->left)<0){
                root->left=LL(root->left);
            }
            return RR(root);
            
        } else if(bf<-1) {
            if(get_bf(root->right)>0){
                root->right=RR(root->right);
            }
            return LL(root);
        }
    
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



Node* inorder_succ(Node* root){
    // guarantee that root is not NIL.
    // find min in right subtree.
    Node* p=root->right;
    // guarantee that p is not NIL.
    while(p->left){
        p=p->left;
    }
    return p;
    
}

Node* AVL_delete(Node* root, int key, int* flag){
    // base case- we have not found our required node- backtrack till root
    if(root==NULL){
        return root;
    }
    if(key<root->key){
        root->left=AVL_delete(root->left, key, flag);
    }
    else if(key>root->key){
        root->right=AVL_delete(root->right, key, flag);
    }
    else{
        (*flag)=1;
        if(root->left==NULL || root->right==NULL){
            Node* temp=root->left ? root->left:root->right;
            if(temp==NULL){
                root=NULL;
            } else{
                root=temp;
                free(temp);
            }
            
        } else {
            // find inorder successor of root
            Node* y=inorder_succ(root);
            // copy the successor's key to the root
            root->key=y->key;
            //delete the successor from root's right subtree
            root->right=AVL_delete(root->right, y->key, flag);
        }
        
    }
    if(root==NULL){
        return root;
    }
    root->height=max(height(root->left), height(root->right))+1;
    int bf=get_bf(root);
    if(bf>1){
            //perform rotations
        if(get_bf(root->left)<0){
            root->left=LL(root->left);
        }
        return RR(root);
            
    } else if(bf<-1) {
        if(get_bf(root->right)>0){
            root->right=RR(root->right);
        }
        return LL(root);
    }
    return root;
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        printf("node val: %d | height: %d ", root->key, root->height);
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
            root = AVL_insert(root, n);
        } else if(x=='d') {
            int n;
            printf("Enter the key you want to delete: ");
            scanf("%d", &n);
            int flag=0;
            root = AVL_delete(root, n, &flag);
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
