// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     1 
//                   1 2 3
//                 1 2 3 4 5
//               1 2 3 4 5 6 7
//             1 2 3 4 5 6 7 8 9

#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 1;i <= row;i++){
        for(int j = 1;j <= row - i;j++){
            cout<<" ";
        }
        for(int k = 1;k <= (2 * i - 1);k++){
            cout<<k;
        }
        cout<<endl;
    }
}