// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     1 
//                     1  2 
//                     1  2  3 
//                     1  2  3  4 
//                     1  2  3  4  5 
//                     1  2  3  4 
//                     1  2  3 
//                     1  2 
//                     1 

#include <iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 1;i <= row;i++){
        for(int j = 1;j <= i;j++){
            cout<<" "<<j<<" ";
        }
        cout<<endl;
    }
    for(int i = (row - 1);i > 0;i--){
        for(int j = 1;j <= i;j++){
            cout<<" "<<j<<" ";
        }
        cout<<endl;
    }
}