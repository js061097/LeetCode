class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1){
            return s;
        }
        
        string answer[numRows];
        string final_ans;
        
        int jump = 2*(numRows - 1);
        
        
            for(int j=0;j<numRows;j++){ 
                for(int i=j;i<s.size();i+=jump){
                    answer[j].push_back(s[i]);
                    if(j>0 && j<numRows-1){
                        if((i+jump-2*j)<s.size())
                        {answer[j].push_back(s[i+jump-2*j]);}
                    }
                }
                cout<<endl<<answer[j];
                final_ans.append(answer[j]);
            }
        
        return final_ans;
        
    }
};




