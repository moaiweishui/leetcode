//DP
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        
        vector<int> res(n + 1, 0);
        res[1] = 0;
        res[2] = 1;
        int temp;
        int maxproduct = 0;
        for(int i = 3; i <= n; i++)
        {
            for(int j = 1; j <= i/2; j++)
            {
                temp = j * max(i - j, res[i - j]);
                if(temp > maxproduct)
                    maxproduct = temp;
            }
            res[i] = maxproduct;
        }
        return res[n];
    }
};
