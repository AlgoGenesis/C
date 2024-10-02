// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                        *
//                      * *
//                    * * *
//                  * * * *
//                * * * * *
//                  * * * *
//                    * * *
//                      * *
//                        *

#include <iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = row;i > 0;i--){
        for(int j = 0;j < (i - 1);j++){
            cout<<" ";
        }
        for(int k = 0;k < (row - i + 1);k++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i = (row - 1);i >= 1;i--){
        for(int j = i;j < row;j++){
            cout<<" ";
        }
        for(int k = 0;k < i;k++){
            cout<<"*";
        }
        cout<<endl;
    }
}