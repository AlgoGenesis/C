// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     e d c b a 
//                     e d c b 
//                     e d c 
//                     e d 
//                     e 

#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 1;i <= 5;i++){
        for(int j = row;j >= i;j--){
            cout<<(char)(j + 96)<<" ";
        }
        cout<<endl;
    }
}