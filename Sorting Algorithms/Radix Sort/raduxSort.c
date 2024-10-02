#include <iostream>
#include <cmath>

using namespace std;

template <class T>
void Print(T& vec, int n, const string& s) {
    cout << s << ": [";
    for (int i = 0; i < n; i++) {
        cout << vec[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int Max(int A[], int n) {
    int max = A[0]; // Initialize to the first element
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

// Linked List node
class Node {
public:
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {} // Constructor for easier node creation
};

int countDigits(int x) {
    if (x == 0) return 1; // Handle zero case
    int count = 0;
    while (x != 0) {
        x /= 10;
        count++;
    }
    return count;
}

void initializeBins(Node** p, int n) {
    for (int i = 0; i < n; i++) {
        p[i] = nullptr;
    }
}

void Insert(Node** ptrBins, int value, int idx) {
    Node* temp = new Node(value); // Use constructor
    if (ptrBins[idx] == nullptr) {
        ptrBins[idx] = temp; // Head pointer
    } else {
        Node* p = ptrBins[idx];
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node** ptrBins, int idx) {
    Node* p = ptrBins[idx]; // Head pointer
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

int getBinIndex(int x, int idx) {
    return (x / static_cast<int>(pow(10, idx))) % 10; // Use static_cast for clarity
}

void RadixSort(int A[], int n) {
    int max = Max(A, n);
    int nPass = countDigits(max);

    // Create bins array
    Node** bins = new Node*[10];
    initializeBins(bins, 10);

    // Update bins and A for nPass times
    for (int pass = 0; pass < nPass; pass++) {
        // Update bins based on A values
        for (int i = 0; i < n; i++) {
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }

        // Update A with sorted elements from bins
        int j = 0;
        for (int i = 0; i < 10; i++) {
            while (bins[i] != nullptr) {
                A[j++] = Delete(bins, i);
            }
        }
        // Re-initialize bins
        initializeBins(bins, 10);
    }

    // Clean up allocated memory
    delete[] bins;
}

int main() {
    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    int n = sizeof(A) / sizeof(A[0]);

    Print(A, n, "\t\tA");
    RadixSort(A, n);
    Print(A, n, " Sorted A");

    return 0;
}
