class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        if(amount == 0)
            return 1;
        else if(len == 0)
            return 0;
        else if(len == 1)
            return amount % coins[0] == 0 ? 1 : 0;
        
        vector<int> rowv(amount+1, 1);
        vector<vector<int>> mem(len, rowv);
        
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < len; j++)
            {
                if(j == 0 && (i % coins[0] != 0))
                    mem[j][i] = 0;
                else if(j != 0)
                {
                    if(i - coins[j] >= 0)
                        mem[j][i] = mem[j - 1][i] + mem[j][i - coins[j]];
                    else
                        mem[j][i] = mem[j - 1][i];
                }
            }
        }
        
        return mem[len - 1][amount];
    }
};
