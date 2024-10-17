#include<bits/stdc++.h>

using namespace std;
int trap(vector < int > & height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int raintrap = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        raintrap += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        raintrap += maxRight - height[right];
      }
      right--;
    }
  }
  return raintrap;
}

int main() {
  vector < int > arr;
  arr = {3,0,1,2,8,0,4,5,0,2};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}

