//This program takes a input sequence of digits(0-9) from the user and prints all possible combinations
//of letters that those numbers could represent on a phone's keypad
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
//This function recursively generate all possible combinations of letters
//corresponding to the numbers in input sequence(keypad phone)
void combo(const vector<int>& a,const vector<string>& mp,int i,string curr,vector<string>& res){
    if (i==a.size()){
        res.push_back(curr);
        return;
    }
    string chars = mp[a[i]];
    for (char c:chars){
        combo(a,mp,i+1,curr+c,res);
    }
}
//This function takes the vector of digits(2-9) and generates all possible letter combinations recursively
//by mapping the letter combinations to numbers using mp vector
vector<string> possiblewords(const vector<int>& a){
    vector<string>mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>res;
    combo(a,mp,0,"",res);
    return res;
}
int main(){
    string n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Possible Combinations of letters are: ";
    vector<int>a;
    for (char x:n){
        if (isdigit(x) && 2<=(x-'0') && (x-'0')<=9){
            a.push_back(x-'0');
        }
    }
    vector<string>res = possiblewords(a);
    for (const string& word:res){
        cout<<word<<" ";
    }
    cout<<endl;
    return 0;
}