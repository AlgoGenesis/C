// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     a a a a a 
//                     b b b b 
//                     c c c 
//                     d d 
//                     e 

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 1;i <= row;i++){
        for(int j = i;j <= row;j++){
            cout<<(char)(i + 96)<<" ";
        }
        cout<<endl;
    }
}