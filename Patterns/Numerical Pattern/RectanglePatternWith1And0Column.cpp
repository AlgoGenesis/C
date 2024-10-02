// Write a C++ program to generate following pattern
// Enter no. of rows : 4
// Enter no. of columns : 5
//                    0 1 0 1 0 
//                    0 1 0 1 0 
//                    0 1 0 1 0 
//                    0 1 0 1 0 

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
            if(j % 2 == 0){
                cout<<0<<" ";
            }
            else{
                cout<<"1"<<" ";
            }
        }
        cout<<endl;
    }
}