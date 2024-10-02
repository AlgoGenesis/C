// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     A B C D E 
//                     A B C D 
//                     A B C 
//                     A B 
//                     A 

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = row;i >= 1;i--){
        for(int j = 1;j <= i;j++){
            cout<<(char)(j + 64)<<" ";
        }
        cout<<endl;
    }
}