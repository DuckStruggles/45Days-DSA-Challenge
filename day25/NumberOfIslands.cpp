#include <iostream>
#include <vector>
using namespace std;

int m, n;

void dfs(vector<vector<char>> &grid, int r, int c) {
    if(r<0 || c<0 || r>=m || c>=n || grid[r][c]=='0') {
        return;
    }

    grid[r][c]='0';

    dfs(grid, r-1, c);
    dfs(grid, r+1, c);
    dfs(grid, r, c-1);
    dfs(grid, r, c+1);
}

int numberIslands(vector<vector<char>> &grid) {
    m=grid.size();
    n=grid[0].size();
    int count=0;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j]=='1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    int count = numberIslands(grid);

    cout << "Number of islands is: " << count;
    return 0;
}