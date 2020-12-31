
#include <vector>
#include <climits>

using namespace std;


class Solution {

public:

    int coinChange(vector<int>& coins, int amount) 
    {
        
        int dp [amount+1];

        for (int i = 0; i <= amount; ++i)
        {
        	dp[i] = INT_MAX-1;
        }

        dp[0] = 0;

        for (int i = 1; i <= amount; ++i)
        {
        	for (int coin : coins)
        	{
        		int res = i-coin;

        		if (res < 0 or dp[res]<0)
        			continue;

        		dp[i] = min(dp[i], dp[res]+1);
        	}
        }

        return dp[amount] == INT_MAX-1? -1: dp[amount];
    }
};