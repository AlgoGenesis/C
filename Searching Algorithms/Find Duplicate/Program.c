#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(const vector<int>& arr)
{
    vector<int> res;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                // Check if the duplicate element is already in res
                auto it = find(res.begin(), res.end(), arr[i]);

                if (it == res.end())
                {
                    // Add the element to res if not already present
                    res.push_back(arr[i]);
                }
                break; // Move to the next element in arr
            }
        }
    }

    return res;
}


int main()
{
    vector<int> arr = {3,51,81,24,9,51,80,24};
    vector<int> duplicates = findDuplicates(arr);
    for (int i = 0; i < duplicates.size(); i++)
        cout << duplicates[i] << " ";    
    return 0;
}
