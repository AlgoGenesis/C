// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     1
//                    123
//                   12345
//                  1234567
//                 123456789
//                  1234567
//                   12345
//                    123
//                     1

#include <iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 1;i <= row;i++){
        for(int j = 1;j <= (row - i);j++){
            cout<<" ";
        }
        for(int j = 1;j <= (2 * i - 1);j++){
            cout<<j;
        }
        cout<<endl;
    }
    for(int i = (row - 1);i >= 1;i--){
        for(int j = 1;j <= (row - i);j++){
            cout<<" ";
        }
        for(int j = 1;j <= (2 * i - 1);j++){
            cout<<j;
        }
        cout<<endl;
    }
}