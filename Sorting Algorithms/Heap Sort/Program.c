//basic C header file
#include<stdio.h>

//function to heapify a subtree rooted with node i
void heapify(int arr[],int n,int i){
    int largest=i; //initialize largest  element as root 
    int left=2*i+1; // left=2*i+1;
    int right=2*i+2;  //right=2*i+2;

    ///if left child is larger than root
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }

    //if right child is larger than largest
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
        //if largest is not root
        if(largest !=i){
            int temp=arr[i];
            arr[i]=arr[largest];
            arr[largest]=temp;

            //recursively heapify the affected sub-tree
            heapify(arr,n,largest);
        }
    }

    //main function to do heap sort
    void heapsort(int arr[],int n){
        //build heap (rearrange array)
        for(int i=n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }

        //one by one extract element from heap
        for(int i=n-1;i>0;i--){
            //move current root to end
            int temp=arr[0];
            arr[0]=arr[i];
            arr[i]=temp;

            //call heapify
            heapify(arr,i,0);
        }
    }
// function to print array
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {78, 650, 10, 21, 23, 12, 90, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:- \n");
    print_array(arr, n);

    heapsort(arr, n);

    printf("Sorted array:- \n");
    print_array(arr, n);
    return 0;
}