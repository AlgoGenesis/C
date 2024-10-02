// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     A B C D E 
//                     B C D E 
//                     C D E 
//                     D E 
//                     E 

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 1;i <= row;i++){
        for(int j = i;j <= row;j++){
            cout<<(char)(j + 64)<<" ";
        }
        cout<<endl;
    }
}