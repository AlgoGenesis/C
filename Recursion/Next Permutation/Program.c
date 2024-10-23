// C++ Program to find the next permutation by generating 
// all permutations

#include <bits/stdc++.h>
using namespace std;

// Generates all permutations
void permutations(vector<vector<int>>& result, vector<int>& curr, 
                  int idx);

// Function to get the next permutation
void nextPermutation(vector<int>& arr) {
  
    // Generate all permutations and store in res
    vector<vector<int>> result;
    permutations(result, arr, 0);
    sort(result.begin(), result.end());

    // Traverse through res and find the next permutation
    for (int i = 0; i < result.size(); i++) {
      
        // Found a match
        if (result[i] == arr) {
          
            // Store the next
            if (i < result.size() - 1)
                arr = result[i + 1];
          
            // If the given permutation is the last
            if (i == result.size() - 1)
                arr = result[0];
          
            break;
        }
    }
}

// Function to generate all possible permutations
void permutations(vector<vector<int>>& res, vector<int>& arr, 
                  int idx) {
  
    // Base case: if idx reaches the end of the array
    if (idx == arr.size() - 1) {
        res.push_back(arr);
        return;
    }

    // Permutations made by swapping each element
    // starting from index idx
    for (int i = idx; i < arr.size(); i++) {
      
        // Swapping
        swap(arr[idx], arr[i]);

        // Recursive call to create permutations
        // for the next element
        permutations(res, arr, idx + 1);

        // Backtracking
        swap(arr[idx], arr[i]);
    }
}

int main() {
    vector<int> arr = { 2, 4, 1, 7, 5, 0 };
    nextPermutation(arr);
  
      for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}