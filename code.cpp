class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        
        // int res=solve(coins,amount,n-1,dp);
        // return res!=100001?res:-1;
        int dp[n+1][amount+1];
        for(int j=0;j<amount+1;j++)
        {
            if(j%coins[0]==0)
            dp[0][j]=j/coins[0];
            else
            dp[0][j]=100001;
        }
        for(int i=0;i<n+1;i++)
        dp[i][0]=0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(j-coins[i-1]>=0)
                dp[i][j]=min(1+dp[i-1][j-coins[i-1]],min(1+dp[i][j-coins[i-1]]
                ,dp[i-1][j]));
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][amount]!=100001?dp[n][amount]:-1;
    }
};
