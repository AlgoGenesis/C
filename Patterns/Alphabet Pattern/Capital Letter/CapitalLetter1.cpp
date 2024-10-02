// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     E E E E E 
//                     D D D D 
//                     C C C 
//                     B B 
//                     A

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = row;i > 0;i--){
        for(int j = 1;j <= i;j++){
            cout<<(char)(i + 64)<<" ";
        }
        cout<<endl;
    }
}