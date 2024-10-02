// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//             a b c d e f g h i
//               a b c d e f g
//                 a b c d e
//                   a b c 
//                     a 
   
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
            cout<<(char)(j + 96);
        }
        cout<<endl;
    }
}