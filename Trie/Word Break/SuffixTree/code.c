#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct Node {
    struct Node *children[MAX_CHAR];
    int start, end;
    struct Node *suffix_link;
} Node;

Node *create_node(int start, int end) {
    Node *node = (Node *)malloc(sizeof(Node));
    memset(node->children, 0, sizeof(node->children));
    node->start = start;
    node->end = end;
    node->suffix_link = NULL;
    return node;
}

void build_suffix_tree(char *text, Node *root) {
    int n = strlen(text);
    int active_node = 0, active_edge = 0, active_length = 0;
    int last_prefix_length = 0;

    for (int i = 0; i < n; i++) {
        // Add the new character to the suffix tree
        while (active_length != 0 && text[i] != text[root->children[active_edge]->start + active_length]) {
            active_length = active_node == 0 ? active_length - 1 : 0;
            active_edge = root->children[active_edge]->suffix_link ? root->children[active_edge]->suffix_link->children[text[i]] : 0;
            active_node = active_edge ? root->children[active_edge]->start : 0;
        }

        // Create a new node if necessary
        if (active_length == 0 || text[i] != text[root->children[active_edge]->start + active_length]) {
            Node *new_node = create_node(i, n - 1);
            if (active_node == 0) {
                root->children[text[i]] = new_node;
            } else {
                Node *temp = root->children[active_edge];
                root->children[active_edge] = new_node;
                new_node->children[text[temp->start + active_length]] = temp;
                temp->start += active_length;
            }

            if (root->suffix_link) {
                new_node->suffix_link = root->suffix_link->children[text[i]];
            } else {
                new_node->suffix_link = root;
            }
        }

        // Update active node, edge, and length
        active_node = root->children[active_edge]->start;
        active_length++;
        if (active_length > last_prefix_length) {
            last_prefix_length = active_length;
            if (active_node != 0) {
                root->suffix_link = root->children[active_edge];
            }
        }
    }
}

// Function to print the suffix tree
void print_suffix_tree(Node *root, int depth) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < MAX_CHAR; i++) {
        if (root->children[i] != NULL) {
            printf("%*s%d-%d\n", depth * 2, "", root->children[i]->start, root->children[i]->end);
            print_suffix_tree(root->children[i], depth + 1);
        }
    }
}

int main() {
    char text[] = "banana";
    int n = strlen(text);

    Node *root = create_node(0, n - 1);
    build_suffix_tree(text, root);

    printf("Suffix Tree:\n");
    print_suffix_tree(root, 0);

    return 0;
}