/*

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.

*/

class Trie {
public: 
    Trie *node[26];
    bool isEnd;
    Trie() {
        for(int i=0;i<26;++i) {
            node[i] = nullptr;
        }
        isEnd = false;
    }
    void insert(string word) {
        Trie *root = this;
        for(int i=0;i<word.size();++i) {
            if (!root->node[word[i]-'a']) {
                root->node[word[i]-'a'] = new Trie();
            }
            root = root->node[word[i]-'a'];
        }
        root->isEnd = true;
    }
    bool search(string word) {
        Trie *root = this;
        for(int i=0;i<word.size();++i) {
            if(!root->node[word[i]-'a']) {
                return false;
            }
            root = root->node[word[i]-'a'];
        }
        return root->isEnd;
    }
};
class Solution {
    set<string> result;
    int row,col;
    void dfs(vector<vector<char>> &board,int i,int j,string run,const Trie *root) {
        if (i < 0 || i>=row ||j<0 ||j>=col || board[i][j] == '-') return;
        char temp = board[i][j];
        if (root->node[temp-'a']) {
            if (root->node[temp-'a']->isEnd) {
                result.insert(run+temp);
            }
            board[i][j] = '-';
            dfs(board,i+1,j,run+temp,root->node[temp-'a']);
            dfs(board,i,j+1,run+temp,root->node[temp-'a']);
            dfs(board,i-1,j,run+temp,root->node[temp-'a']);
            dfs(board,i,j-1,run+temp,root->node[temp-'a']);
        }
        board[i][j] = temp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row = board.size();
        col = board[0].size();
        Trie *root = new Trie();
        for(int i = 0;i<words.size();++i) {
            root->insert(words[i]);
        }
        for(int i=0;i<row;++i) {
            for(int j =0;j<col;++j) {
                dfs(board,i,j,"",root);
            }
        }
        return vector<string>(result.begin(),result.end());
    }
};