#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
    struct node *parent;
    char color;
} Node;

Node *create(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->left = NULL;
    p->right = NULL;
    p->parent = NULL;
    p->color = 'r';
    return p;
}

Node *LL(Node *node, Node **root) {
    Node *child = node->right;
    node->right = child->left;
    if (child->left) {
        child->left->parent = node;
    }
    child->parent = node->parent;
    if (node->parent == NULL) {
        *root = child;
    } else if (node == node->parent->right) {
        node->parent->right = child;
    } else {
        node->parent->left = child;
    }
    child->left = node;
    node->parent = child;
    return child;
}

Node *RR(Node *node, Node **root) {
    Node *child = node->left;
    node->left = child->right;
    if (child->right) {
        child->right->parent = node;
    }
    child->parent = node->parent;
    if (node->parent == NULL) {
        *root = child;
    } else if (node == node->parent->left) {
        node->parent->left = child;
    } else {
        node->parent->right = child;
    }
    child->right = node;
    node->parent = child;
    return child;
}

Node *RB_fixup(Node *z, Node *root) {
    // While the parent of z is red, perform fix-up operations
    while (z->parent && z->parent->color == 'r') {
        // If z's parent is a left child
        if (z->parent->parent && z->parent == z->parent->parent->left) {
            Node *y = z->parent->right; // y is the sibling of z's parent
            // Case 1: If the sibling y is red, perform recoloring
            if (y && y->color == 'r') {
                z->parent->color = 'b'; // Change parent to black
                y->color = 'b'; // Change sibling to black
                z->parent->parent->color = 'r'; // Change grandparent to red
                z = z->parent->parent; // Move up to the grandparent
            } else {
                // Case 2: If z is the right child, perform left rotation
                if (z->parent->right && z == z->parent->right) {
                    z = z->parent; // Move up to parent
                    LL(z, &root); // Perform left rotation
                }
                // Case 3: Recolor and perform right rotation
                z->parent->color = 'b'; // Change parent to black
                if (z->parent->parent) {
                    z->parent->parent->color = 'r'; // Change grandparent to red
                    RR(z->parent->parent, &root); // Perform right rotation
                }
            }
        } else { // If z's parent is a right child
            Node *y = z->parent->left; // y is the sibling of z's parent
            // Case 1: If the sibling y is red, perform recoloring
            if (y && y->color == 'r') {
                z->parent->color = 'b'; // Change parent to black
                y->color = 'b'; // Change sibling to black
                z->parent->parent->color = 'r'; // Change grandparent to red
                z = z->parent->parent; // Move up to the grandparent
            } else {
                // Case 2: If z is the left child, perform right rotation
                if (z->parent->left && z == z->parent->left) {
                    z = z->parent; // Move up to parent
                    RR(z, &root); // Perform right rotation
                }
                // Case 3: Recolor and perform left rotation
                z->parent->color = 'b'; // Change parent to black
                if (z->parent->parent) {
                    z->parent->parent->color = 'r'; // Change grandparent to red
                    LL(z->parent->parent, &root); // Perform left rotation
                }
            }
        }
    }
    // Ensure the root of the tree is always black
    root->color = 'b';
    return root; // Return the updated root
}


Node *RB_insert(Node *root, int key) {
    // Create a new node with the given key
    Node *p = create(key);
    
    // If the tree is empty, the new node becomes the root
    if (root == NULL) {
        root = p;
    } else {
        Node *t = NULL;
        Node *q = root;
        
        // Traverse the tree to find the correct position for the new node
        while (q) {
            t = q; // Track the parent of the current node
            if (q->key == key) {
                free(p); // Avoid memory leak if the key already exists
                return root;
            } else if (q->key > key) {
                q = q->left; // Go left if the key is smaller
            } else {
                q = q->right; // Go right if the key is larger
            }
        }
        // Set the parent for the new node and link it to the tree
        p->parent = t;
        if (t->key > key) {
            t->left = p; // Link as left child
        } else {
            t->right = p; // Link as right child
        }
    }
    // Fix any violations of the red-black tree properties after insertion
    root = RB_fixup(p, root);
    return root;
}

void delete_helper(Node **root, Node *x) {
    // Fix up the tree after a deletion to maintain red-black properties
    while (x != (*root) && x->color == 'b') {
        Node *temp = NULL;

        // Handle case where x is a left child
        if ((x->parent->left != NULL) && (x == x->parent->left)) {
            temp = x->parent->right;
            // Case when sibling is red
            if ((temp != NULL) && (temp->color == 'r')) {
                temp->color = 'b';
                x->parent->color = 'r';
                LL(x->parent, root); // Perform left rotation
                temp = x->parent->right; // Update sibling
            }
            // Case when both children of sibling are black
            if ((temp != NULL) && (temp->right != NULL) && (temp->left != NULL) && 
                (temp->left->color == 'b') && (temp->right->color == 'b')) {
                temp->color = 'r';
                x = x->parent; // Move up the tree
            } else if ((temp != NULL) && (temp->right->color == 'b')) {
                // Case when left child of sibling is black
                temp->left->color = 'b';
                temp->color = 'r';
                RR(temp, root); // Perform right rotation
                temp = x->parent->right; // Update sibling
            }
            // Adjust colors and rotations as necessary
            if (temp != NULL) {
                temp->color = x->parent->color;
                x->parent->color = 'b';
                temp->right->color = 'b';
                LL(x->parent, root);
                x = (*root);
            }
        }
        // Handle case where x is a right child
        else if (x->parent != NULL) {
            temp = x->parent->left;
            if ((temp != NULL) && (temp->color == 'r')) {
                temp->color = 'b';
                x->parent->color = 'r';
                LL(x->parent, root);
                if (x->parent != NULL) {
                    temp = x->parent->left; // Update sibling
                }
            }
            // Case when both children of sibling are black
            if ((temp != NULL) && (temp->right != NULL) && (temp->left != NULL) &&
                (temp->right->color == 'b') && (temp->left->color == 'b')) {
                x = x->parent; // Move up the tree
            } else if ((temp != NULL) && (temp->right != NULL) && 
                       (temp->left != NULL) && (temp->left->color == 'b')) {
                // Case when left child of sibling is black
                temp->right->color = 'b';
                temp->color = 'r';
                RR(temp, root); // Perform right rotation
                temp = x->parent->left; // Update sibling
            }
            // Adjust colors and rotations as necessary
            if (x->parent != NULL) {
                temp->color = x->parent->color;
                x->parent->color = 'b';
            }
            if (temp->left != NULL)
                temp->left->color = 'b'; // Ensure left child is black
            if (x->parent != NULL) {
                LL(x->parent, root); // Perform left rotation
            }
            x = (*root);
        }
    }
    // Ensure the root is always black
    x->color = 'b';
}

Node *successor(Node *node) {
    Node *successor = node->right;
    while (successor->left) {
        successor = successor->left;
    }
    return successor;
}

Node *RB_delete(Node *root, int key) {
    Node *x = NULL;
    Node *y = NULL;
    Node *z = root;

    // If the tree is empty, return
    if (root == NULL) return NULL;

    // Find the node to delete
    while (z != NULL && z->key != key) {
        if (key < z->key) {
            z = z->left; // Go left
        } else {
            z = z->right; // Go right
        }
    }
    // If the key is not found, return
    if (z == NULL) return root;

    // Determine the node to be deleted and its successor
    if (z->left == NULL || z->right == NULL) {
        y = z; // Node to delete is either a leaf or has one child
    } else {
        y = successor(z); // Get the in-order successor
    }

    // Determine the child of the node to be deleted
    if (y->left != NULL) {
        x = y->left;
    } else {
        x = y->right;
    }

    // Update the parent pointer of the child node, if it exists
    if (x != NULL) x->parent = y->parent;

    // Adjust the parent's pointer to the child
    if (y->parent == NULL) {
        root = x; // y is root
    } else if (y == y->parent->left) {
        y->parent->left = x; // Link child to parent's left
    } else {
        y->parent->right = x; // Link child to parent's right
    }

    // Copy the key from y to z if needed
    if (y != z) {
        z->key = y->key;
    }

    // If the deleted node was black, fix any violations
    if (y->color == 'b') {
        delete_helper(&root, x);
    }
    
    // Free the memory of the deleted node
    free(y);
    return root;
}

void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d %c  ", root->key, root->color);
        inorder(root->right);
    }
}

int main() {
    Node *root = NULL;
    root = RB_insert(root, 41);
    root = RB_insert(root, 38);
    root = RB_insert(root, 31);
    root = RB_insert(root, 12);
    root = RB_insert(root, 19);
    root = RB_insert(root, 8);
    printf("Inorder before deletion:\n");
    inorder(root);
    printf("\n");
    root = RB_delete(root, 41);
    printf("Inorder after deletion:\n");
    inorder(root);
    printf("\n");
    return 0;
}
