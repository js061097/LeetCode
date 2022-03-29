class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> sub_res;
        string dots(n,'.');
        vector<int> board(n,-1);
        //placing the first queen
        for(int i=0;i<n;i++){
            board[0] = i;
            backtrack(i,0,1,n,dots,sub_res,res,board);
        }
        
        return res;
        
    }
    void backtrack(int r, int c, int iter, int n, string dots,vector<string> sub_res, vector<vector<string>> &res, vector<int> board){
        
        //checking conditions - not same row or diagonal of previous queens
        for(int i=0;i<=c-1;i++){
            if(abs(r-board[i])==0 || (abs(r-board[i])==abs(c-i))){
                return;
            }
        }
        
        //if the new place for queen is acceptable
        
            dots[board[c]] = 'Q';
            sub_res.push_back(dots);
            dots[board[c]] = '.';
        
        //stopping condition
        if(iter==n){
            res.push_back(sub_res);
            return;
        }
            
        //next column queen placement
        for(int i=0;i<n;i++){
            board[c+1] = i;
            backtrack(i,c+1,iter+1,n,dots,sub_res,res,board);
        }
    }
};

/*
no attack - no same row, col or diag

if there's a queen at i,j
then no queens at 
i+k,j+k diff k,k
i-k,j-k diff -k,-k
i+k,j-k diff k,-k
i-k,j+k diff -k,k

*/
