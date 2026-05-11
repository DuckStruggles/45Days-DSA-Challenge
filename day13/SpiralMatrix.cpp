#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> mat)
{
    int m = mat.size(), n = mat[0].size();
    int sr = 0, sc = 0, er = m - 1, ec = n - 1;
    vector<int> ans;

    while (sr <= er && sc <= ec)
    {
        for (int i = sc; i <= ec; i++)
        {
            ans.push_back(mat[sr][i]);
        }
        sr++;

        for (int i = sr; i <= er; i++)
        {
            ans.push_back(mat[i][ec]);
        }
        ec--;

        if (sr <= er)
        {
            for (int i = ec; i >= sc; i--)
            {
                ans.push_back(mat[er][i]);
            }
            er--;
        }

        if(sc <= ec) {
            for(int i=er; i>=sr; i--) {
                ans.push_back(mat[i][sc]);
            }
            sc++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Matrix\n";
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> ans = spiralMatrix(mat);
    cout << "Spiral Matrix representation:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}