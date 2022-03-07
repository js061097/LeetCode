class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(backtrack(board,word,i,j,0))
                    return true;
            }
        }
        return false;
        
    }
    bool backtrack(vector<vector<char>>& board, string word, int m, int n, int pos){
        if(pos==word.size())
            return true;
        if(m>= board.size() || n>= board[0].size() || m<0 || n<0 || board[m][n]!=word[pos])
            return false;
        char c = board[m][n];
        board[m][n] = '1';
        bool res = backtrack(board,word,m+1,n,pos+1) || backtrack(board,word,m,n+1,pos+1) || backtrack(board,word,m-1,n,pos+1) || backtrack(board,word,m,n-1,pos+1);
        board[m][n] = c;
        return res;
        
    }
};
/*
Whenever the character reqd is visited change that char to a number (to show it's visited)

*/
