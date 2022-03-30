class Solution {
public:
    int mySqrt(int x) {
        int num = 0;
        int i = 1;
        while(x>0){
            x-=i;
            i+=2;
            num+=1;
        }
        if(x<0)
            return num-1;
        return num;
    }
};
