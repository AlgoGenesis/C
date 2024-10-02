// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     e e e e e 
//                     d d d d 
//                     c c c 
//                     b b 
//                     a 

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = row;i > 0;i--){
        for(int j = 1;j <= i;j++){
            cout<<(char)(i + 96)<<" ";
        }
        cout<<endl;
    }
}