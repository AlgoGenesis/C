// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     *
//                    ***
//                   *****
//                  *******
//                 *********
//                  *******
//                   *****
//                    ***
//                     *

#include <iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 0;i < row;i++){
        for(int j = 0;j < row - i - 1;j++){
            cout<<" ";
        }
        for(int k = 0;k < (2 * i + 1);k++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i = row - 1;i > 0;i--){
        for(int j = 0;j < row - i;j++){
            cout<<" ";
        }
        for(int k = 0;k < (2 * i - 1);k++){
            cout<<"*";
        }
        cout<<endl;
    }
}