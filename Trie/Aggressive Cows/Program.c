#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>&arr, int minAllocateddist, int N, int K) {
	int cow = 1;
	int prev = arr[0];
	for (int i=1;i<N;i++)
     {
		if(arr[i]- prev >= minAllocateddist) {
			prev = arr[i];
			cow++;
		}
	}

	if (cow >= K){
      return true;  
    } 
	return false;
}
int getDistance(vector<int>&arr,int N,int K)
{
    sort(arr.begin(),arr.end());
    int st=1,end=arr[N-1],ans=-1;
    while(st<=end)
    {
        int mid=st+(end-st)/2;
        if(isPossible(arr,N,K,mid)){
            ans=mid;
            st=mid-1;
        }
        else{
            end=mid-1;
        }
        }
    }

int main() {
	int N = 5, K = 3;
	vector<int> arr = { 1, 2, 4, 8, 10 };
	cout<<getDistance(arr,N,K)<<endl;
    return 0;
}