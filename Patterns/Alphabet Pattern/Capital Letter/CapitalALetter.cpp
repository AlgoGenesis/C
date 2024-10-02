// Write a C++ program to generate following pattern
// Enter no. of rows : 5
// Enter no. of columns : 4
//                     A A A A 
//                     A A A A 
//                     A A A A 
//                     A A A A 
//                     A A A A 

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
            cout<<"A"<<" ";
        }
        cout<<endl;
    }
}