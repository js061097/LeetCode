class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()==1)
            return true;
        
        map<char,char> sc;
        map<char,char> tc;
        for(int i=0;i<s.length();i++)
        {   if((sc.find(s[i])!=sc.end() && sc[s[i]]!=t[i]) || (tc.find(t[i])!=tc.end() && tc[t[i]]!=s[i]))
            return false;
            sc[s[i]] = t[i];
            tc[t[i]] = s[i];
        }
        return true;
    }
};
