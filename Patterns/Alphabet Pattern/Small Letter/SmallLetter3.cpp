// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     a b c d e 
//                     a b c d 
//                     a b c 
//                     a b 
//                     a 

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = row;i >= 1;i--){
        for(int j = 1;j <= i;j++){
            cout<<(char)(j + 96)<<" ";
        }
        cout<<endl;
    }
}