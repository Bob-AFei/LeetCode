class Solution {

public:

    int fib(int n) 
    {
    	int pre_pre = 1;
    	int pre     = 1;
    	int ans     = 0;

    	if (n == 1)
    		return pre_pre;

    	if (n == 2)
    		return pre;

    	for (int i = 0; i < n-2; ++i)
    	{
    		ans = pre_pre+pre;
    		pre_pre = pre;
    		pre = ans;
    	}
    	return ans;
    }

};
