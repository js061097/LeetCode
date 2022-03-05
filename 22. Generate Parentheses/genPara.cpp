class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> solution;
        string currStr;
        genPara(n,0,0,currStr,solution);
        return solution;
    }
    void genPara(int n, int open, int close, string currStr, vector<string>& solution)     {
        if(open == close && open==n)
        {
            solution.push_back(currStr);
        }
        if(close>open)
            return;
        if(open>n)
            return;
        currStr.push_back('(');
        genPara(n,open+1,close,currStr,solution);
        currStr.pop_back();
        currStr.push_back(')');
        genPara(n,open,close+1,currStr,solution);
        currStr.pop_back();
        
    }
};
