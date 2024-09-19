#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int maxI = board.size() - 1;
        for (int j = 0; j < board[0].size(); j++){
            if (board[0][j] == 'O'){
                dfs(0, j, board);
            }
            if (board[maxI][j] == 'O'){
                dfs(maxI, j, board);
            }
        }
        int maxJ = board[0].size() - 1;
        for (int i = 0; i < board.size(); i++){
            if (board[i][0] == 'O'){
                dfs(i, 0, board);
            }
            if (board[i][maxJ] == 'O'){
                dfs(i, maxJ, board);
            }
        }
        for (int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'D') board[i][j] = 'O';
            }
        }
    }

    void dfs(int i, int j, vector<vector<char>>& board){
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()){
            return;
        }
        if (board[i][j] == 'X' || board[i][j] == 'D'){
            return;
        }
        board[i][j] = 'D';
        dfs(i - 1, j, board);
        dfs(i + 1, j, board);
        dfs(i, j - 1, board);
        dfs(i, j + 1, board);
    }
};