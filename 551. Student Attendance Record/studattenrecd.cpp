class Solution {
public:
    bool checkRecord(string s) {
        if(s.size()==1)
            return true;
        int abs = 0,late = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A')
                abs++;
            if(abs == 2)
                return false;
            if(s[i] == 'L')
                late++;
            if(late==3)
                return false;
            if(s[i]!='L')
                late = 0;
        }
        return true;
    }
};
