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
    int row,column;
    cout<<"Enter no. of rows : ";
    cin>>row;
    cout<<"Enter no. of columns : ";
    cin>>column;
    for(int i = 0;i < row;i++){
        for(int j = 0;j < column;j++){
            if(i == 0 || i == (row - 1) || j == 0 || j == (column - 1)){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}