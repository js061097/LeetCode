class Solution {
public:
    int romanToInt(string s) {
        map<char,int> rnum = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int res = 0;
        
        int i =0;
            while(i<=s.size()-1){
                if(rnum[s[i]]<rnum[s[i+1]]){
                    res = res + rnum[s[i+1]] - rnum[s[i]];
                    i = i+2;
                }
                else{
                    res = res + rnum[s[i]];
                    i = i + 1;
                }
                cout<<res<<" "<<i<<" "; 
            }
        return res;   
    }
};

/*
max = 3999
MMMCMXCIX
*/
