#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size();
        if(m==0)
        {
            return word.empty();
        }
        if(word.empty())
        {
            return true;
        }
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    visited[i][j] = true;
                    if(find_word(board, word, 1, i, j, visited))
                    {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

private:
    const int direction[4][2] =
        {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
    bool find_word(vector<vector<char>>& board, string word, int index, int x, int y, vector<vector<bool>>& visited)
    {
        if(index==word.size())
        {
            return true;
        }
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<4;i++)
        {
            int tmp_x = x + direction[i][0];
            int tmp_y = y + direction[i][1];
            if(tmp_x<0 || tmp_y<0 || tmp_x>=m || tmp_y>=n)
            {
                continue;
            }
            if(!visited[tmp_x][tmp_y] && board[tmp_x][tmp_y]==word[index])
            {
                visited[tmp_x][tmp_y] = true;
                if(find_word(board, word, index+1, tmp_x, tmp_y, visited))
                {
                    return true;
                }
                visited[tmp_x][tmp_y] = false;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<char>> board =
        {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
        };
    string word = "ABCB";
    Solution s;
    bool res = s.exist(board, word);
    return 0;
}

