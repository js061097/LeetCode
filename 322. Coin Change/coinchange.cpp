class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mincoins(amount + 1,amount+1);
        mincoins[0] = 0;
        if(amount == 0)
            return mincoins[0];
        for(int i=1;i<amount+1;i++){
            for(int c: coins)
            {   
                if(i-c>=0)
                    mincoins[i] = min(mincoins[i], mincoins[i-c]+1);
            }        
        
        }
        return (mincoins[amount]!=amount+1)? mincoins[amount]:-1;
        
    }
};


/*
keep checking if mincoins[amount - max(coins)] ! = 0
if exists
        answer is known
else
        mincoins[amount - ith max(coins)] ! = 0
else 
        return 0
Also coin<amount

eg1: 
1 - 1
2 - 1
3 - 2
4 - 2
5 - 1 
6 - 2
7 - 2
8 - 3 
9 - 3
10 - 2 
11 - 3

[3,4] amount = 6 
6-4 not exist
6-3 exists

*/
