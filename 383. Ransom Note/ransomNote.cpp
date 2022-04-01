class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mag;
        for(char c:magazine){
            if(mag.find(c)==mag.end())
                mag[c] = 1;
            else
                mag[c]++;
        }
        for(char c:ransomNote){
            if(mag.find(c)==mag.end() || mag[c]==0)
                return false;
            else
                mag[c]--;
        }
        return true;
    }
};
