#include <iostream>
#include <unordered_map>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode* random;
    ListNode(int x) : val(x), next(NULL), random(NULL) {}
};

// Function to clone the linked list with random pointers
ListNode* cloneLinkedListWithRandomPointer(ListNode* head) {
    if (!head) return NULL;

    // Step 1: Create an unordered_map to store the mapping from original to cloned nodes
    std::unordered_map<ListNode*, ListNode*> nodeMap;

    // Step 2: First pass to create all nodes (without setting next or random)
    ListNode* curr = head;
    while (curr) {
        nodeMap[curr] = new ListNode(curr->val);  // Map original node to its clone
        curr = curr->next;
    }

    // Step 3: Second pass to set next and random pointers
    curr = head;
    while (curr) {
        nodeMap[curr]->next = nodeMap[curr->next];     // Set the next pointer
        nodeMap[curr]->random = nodeMap[curr->random]; // Set the random pointer
        curr = curr->next;
    }

    // Return the head of the cloned list
    return nodeMap[head];
}

// Helper function to create a linked list from a vector of values and random indices
ListNode* createLinkedList(const std::vector<int>& values, const std::vector<int>& randomIndices) {
    if (values.empty()) return NULL;

    // Create all nodes
    std::vector<ListNode*> nodes;
    for (int val : values) {
        nodes.push_back(new ListNode(val));
    }

    // Set the next pointers
    for (size_t i = 0; i < nodes.size() - 1; ++i) {
        nodes[i]->next = nodes[i + 1];
    }

    // Set the random pointers based on randomIndices
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (randomIndices[i] != -1) {
            nodes[i]->random = nodes[randomIndices[i]];
        }
    }

    return nodes[0];
}

// Helper function to print the linked list along with random pointers
void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        std::cout << "Node(" << curr->val << ")";
        if (curr->random) {
            std::cout << " -> Random(" << curr->random->val << ")";
        } else {
            std::cout << " -> Random(NULL)";
        }
        std::cout << std::endl;
        curr = curr->next;
    }
}

int main() {
    // Define values and random indices for each node
    std::vector<int> values = {1, 2, 3, 4, 5};
    std::vector<int> randomIndices = {2, 4, -1, 0, 1};  // -1 indicates no random pointer

    // Create the linked list with random pointers
    ListNode* originalList = createLinkedList(values, randomIndices);

    std::cout << "Original list with random pointers:\n";
    printLinkedList(originalList);

    // Clone the linked list
    ListNode* clonedList = cloneLinkedListWithRandomPointer(originalList);

    std::cout << "\nCloned list with random pointers:\n";
    printLinkedList(clonedList);

    return 0;
}