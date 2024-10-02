// Write a C++ program to generate following pattern
// Enter no. of rows : 5
// Enter no. of columns : 4
//                     0 0 0 0 
//                     1 1 1 1 
//                     0 0 0 0 
//                     1 1 1 1 
//                     0 0 0 0 

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
            if(i % 2 == 0){
                cout<<0<<" ";
            }
            else{
                cout<<"1"<<" ";
            }
        }
        cout<<endl;
    }
}