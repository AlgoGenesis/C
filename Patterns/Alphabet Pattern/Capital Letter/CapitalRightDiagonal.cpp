// Write a C++ program to generate following pattern
// Enter no. of rows : 5
//                       A
//                      B
//                     C
//                    D
//                   E

#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter no. of rows : ";
    cin>>row;
    for(int i = 1;i <= row;i++){
        for(int j = 1;j <= (row- i);j++){
            cout<<" ";
        }
        for(int j = 1;j <= row;j++){
            if(i == j){
                cout<<(char)(j + 64);
            }
        }
        cout<<endl;
    }
}