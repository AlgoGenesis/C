// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     1 2 3 4 5 
//                     2 3 4 5 
//                     3 4 5 
//                     4 5 
//                     5

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 1;i <= row;i++){
        for(int j = i;j <= row;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}