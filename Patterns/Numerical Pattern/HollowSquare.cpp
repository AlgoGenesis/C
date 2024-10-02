// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                 1 2 3 4 5
//                 1       5
//                 1       5
//                 1       5
//                 1 2 3 4 5

#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 1;i <= row;i++){
        for(int j = 1;j <= row;j++){
            if(i == 1 || i == row || j == 1 || j == row){
                cout<<j;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}