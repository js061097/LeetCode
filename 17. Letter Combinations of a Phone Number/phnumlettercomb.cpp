class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> solution;
        map<char,string> nummap = {
            {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},
            {'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
            
        if(digits.size()){
            backtrack(0,"",digits, nummap,solution);
        }
        return solution;
        
    }
    
    void backtrack(int i, string curStr, string digits, map<char,string> nummap, vector<string>& solution){
        if(curStr.size() == digits.size()){
            solution.push_back(curStr);
            return;
        }
        for(char c:nummap[digits[i]]){
            backtrack(i+1,curStr+c,digits,nummap, solution);
        }
    
    }
    
};
