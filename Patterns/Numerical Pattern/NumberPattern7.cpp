// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     1 1 1 1 1 
//                     2 2 2 2 
//                     3 3 3 
//                     4 4 
//                     5 

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 1;i <= row;i++){
        for(int j = i;j <= row;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}