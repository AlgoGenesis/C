#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlapInter(vector<vector<int>>& arr) {

    // Sort intervals based on start values
    sort(arr.begin(), arr.end());
  
    vector<vector<int>> out;
    out.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        vector<int>& last = out.back();
        vector<int>& curr = arr[i];

        // If current overlaps with the last
        // merged, merge them 
        if (curr[0] <= last[1]) 
            last[1] = max(last[1], curr[1]);
            
        else // Add current to the result
            out.push_back(curr);
    }

    return out;
}

// Driver Code
int main() {
    vector<vector<int>> arr = {{6, 12}, {1, 9}, {2, 4}, {4, 8}};
    vector<vector<int>> out = mergeOverlapInter(arr);

    cout << "The Merged Overlapped Intervals are: ";
    for (const vector<int>& interval : out) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}