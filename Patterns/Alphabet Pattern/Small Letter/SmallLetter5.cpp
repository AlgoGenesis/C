// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     a b c d e 
//                     b c d e 
//                     c d e 
//                     d e 
//                     e 

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 1;i <= row;i++){
        for(int j = i;j <= row;j++){
            cout<<(char)(j + 96)<<" ";
        }
        cout<<endl;
    }
}