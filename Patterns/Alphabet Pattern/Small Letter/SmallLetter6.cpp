// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     e 
//                     e d 
//                     e d c 
//                     e d c b 
//                     e d c b a 

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = row;i >= 1;i--){
        for(int j = row;j >= i;j--){
            cout<<(char)(j + 96)<<" ";
        }
        cout<<endl;
    }
}