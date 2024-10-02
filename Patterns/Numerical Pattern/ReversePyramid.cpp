// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//             1 2 3 4 5 6 7 8 9
//               1 2 3 4 5 6 7
//                 1 2 3 4 5
//                   1 2 3 
//                     1 
 
#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = row;i >= 1;i--){
        for(int j = 1;j <= (row - i);j++){
            cout<<" ";
        }
        for(int j = 1; j <= (2 * i - 1);j++){
            cout<<j;
        }
        cout<<endl;
    }
}