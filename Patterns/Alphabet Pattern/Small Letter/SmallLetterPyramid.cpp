// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                     a 
//                   a b c
//                 a b c d e
//               a b c d e f g
//             a b c d e f g h i

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
            cout<<(char)(k + 96);
        }
        cout<<endl;
    }
}