/*

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

*/

class Solution {
    void dfs(int i,int j,int rsize,int csize,vector<vector<char>> &board) {
        if (i<0 || i>rsize || j<0 || j>csize || board[i][j] != 'O') {
            return;
        }
        cout<<"here"<<endl;
        board[i][j] = '*';
        dfs(i-1,j,rsize,csize,board);
        dfs(i+1,j,rsize,csize,board);
        dfs(i,j-1,rsize,csize,board);
        dfs(i,j+1,rsize,csize,board);
    }
public:
    void solve(vector<vector<char>>& board) {
        int rsize = board.size();
        if (rsize == 0) return;
        int csize = board[0].size();
        for (int i=0;i<rsize;++i) {
            if (board[i][0] == 'O') {
                dfs(i,0,rsize-1,csize-1,board);
            }
            if (board[i][csize-1] == 'O') {
                dfs(i,csize-1,rsize-1,csize-1,board);
            }
        }
        
        for (int j =1;j<csize-1;++j) {
            if (board[0][j] == 'O') {
                dfs(0,j,rsize-1,csize-1,board);
            }
            if (board[rsize-1][j] == 'O') {
                dfs(rsize-1,j,rsize-1,csize-1,board);
            }
        }
        
        for (int i =0;i<rsize;++i) {
            for(int j =0;j<csize;++j) {
                /*if (board[i][j] == '*') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }*/
                if(board[i][j] == 'O')
                 board[i][j] = 'X';
             if(board[i][j] == '*')
                 board[i][j] = 'O';
            }
        }
    }
};