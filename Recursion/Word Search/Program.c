// C++ program to search a word in a 2D grid
#include <bits/stdc++.h>
using namespace std;


// This function checks if the given 
// coordinate is valid
bool validCoordinate(int x, int y, int m, int n) {
    if (x>=0 && x<m && y>=0 && y<n)
        return true;
    return false;
}

// This function searches for the given word
// in a given direction from the coordinate.
bool findWord(int index, string word, vector<vector<char>> &grid,
              int x, int y, int dirX, int dirY) {
    
    // if word has been found
    if (index == word.length()) return true;
    
    // if the current coordinate is 
    // valid and characters match, then
    // check the next index
    if (validCoordinate(x, y, grid.size(), grid[0].size())
        && word[index] == grid[x][y])
        return findWord(index+1, word, grid, x+dirX, 
                        y+dirY, dirX, dirY);
        
    return false;
}

// This function calls search2D for each coordinate
vector<vector<int>>searchWord(vector<vector<char>>grid, 
                              string word){
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<int>>ans;
    
    // x and y are used to set the direction in which
    // word needs to be searched.
    vector<int>x = { -1, -1, -1, 0, 0, 1, 1, 1 };
    vector<int>y = { -1, 0, 1, -1, 1, -1, 0, 1 };
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            
            // Search in all 8 directions
            for (int k=0; k<8; k++) {
                
                // If word is found, then append the 
                // coordinates into answer and break.
                if (findWord(0, word, grid, i, j, x[k], y[k])) {
                    ans.push_back({i,j});
                    break;
                }
            }
        }
    }
    
    return ans;
}

void printResult(vector<vector<int>> ans) {
    for (int i=0; i<ans.size(); i++) {
        cout << "{" << ans[i][0] << "," << ans[i][1] << "}" << " ";
    }
    cout<<endl;
}

int main() {
    vector<vector<char>> grid = {{'a','b','a','b'},
                                 {'a','b','e','b'},
                                 {'e','b','e','b'}};
    string word = "abe";
    
    vector<vector<int>> ans = searchWord(grid, word);
    
    printResult(ans);
}