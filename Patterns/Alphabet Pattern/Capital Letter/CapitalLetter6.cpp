// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     E 
//                     E D 
//                     E D C 
//                     E D C B 
//                     E D C B A

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = row;i >= 1;i--){
        for(int j = row;j >= i;j--){
            cout<<(char)(j + 64)<<" ";
        }
        cout<<endl;
    }
}