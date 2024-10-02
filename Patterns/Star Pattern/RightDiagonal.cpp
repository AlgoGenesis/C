// Write a C++ program to generate following pattern


#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 0;i < row;i++){
        for(int j = 0;j < (row- i - 1);j++){
            cout<<" ";
        }
        for(int j = 0;j < row;j++){
            if(i == j){
                cout<<"*";
            }
        }
        cout<<endl;
    }
}