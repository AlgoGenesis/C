// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                  *
//                  **
//                  * *
//                  *  *
//                  *****

#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 0;i < row;i++){
        for(int j = 0;j <= i;j++){
            if(j == 0 || i == j || i == ( row - 1)){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}