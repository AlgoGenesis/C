// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     1 2 3 4 5 
//                     1 2 3 4 
//                     1 2 3 
//                     1 2 
//                     1 

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = row;i >= 1;i--){
        for(int j = 1;j <= i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}