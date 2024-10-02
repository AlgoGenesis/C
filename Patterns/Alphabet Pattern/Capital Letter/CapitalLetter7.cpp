// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     A A A A A 
//                     B B B B 
//                     C C C 
//                     D D 
//                     E 

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 1;i <= row;i++){
        for(int j = i;j <= row;j++){
            cout<<(char)(i + 64)<<" ";
        }
        cout<<endl;
    }
}