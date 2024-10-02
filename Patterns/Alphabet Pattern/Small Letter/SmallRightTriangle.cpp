// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     a 
//                     a b 
//                     a b c 
//                     a b c d 
//                     a b c d e 

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 1;i <= row;i++){
        for(int j = 1;j <= i;j++){
            cout<<(char)(j + 96)<<" ";
        }
        cout<<endl;
    }
}