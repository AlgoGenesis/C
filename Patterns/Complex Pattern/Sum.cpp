// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     *    
//                     *    
//                 * * * * *
//                     *    
//                     *   

#include <iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 0;i < row;i++){
        for(int j = 0;j < row;j++){
            if(i == (row / 2) || j == (row / 2)){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}