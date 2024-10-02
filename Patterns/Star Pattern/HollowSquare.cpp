// Write a C++ program to generate following pattern
// Enter no. of rows : 4
// Enter no. of columns : 5
//                  *****
//                  *   *
//                  *   *
//                  *****

#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 0;i < row;i++){
        for(int j = 0;j < row;j++){
            if(i == 0 || i == (row - 1) || j == 0 || j == (row - 1)){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}