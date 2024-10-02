// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                 a b c d e
//                 a       e
//                 a       e
//                 a       e
//                 a b c d e

#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 1;i <= row;i++){
        for(int j = 1;j <= row;j++){
            if(i == 1 || i == row || j == 1 || j == row){
                cout<<(char)(j + 96);
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}