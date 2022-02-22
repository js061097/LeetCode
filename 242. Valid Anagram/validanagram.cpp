class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> chars(128,0);
        if(t.size()>s.size())
            return false;
        for(char c:s){
            chars[c]++;
        }
        int remaining = s.size();
        for(char c:t){
            if(chars[c]>0)
            {
                chars[c]--;
                remaining--;
            }    
            
        }
        if(remaining==0)
            return true;
        else
            return false;
    }
};
