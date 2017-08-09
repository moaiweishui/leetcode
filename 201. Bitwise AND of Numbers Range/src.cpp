class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m;
        if(m == n)
            return res;
        else if(m == 0)
            return 0;
        
        if(n - m < 10000)
        {
            for(double i = m + 1; i <= n; i++)
            {
                res = res & int(i);
            }
            return res;
        }
        
        int x = m;
        int y = n;
        int len1 = 0;
        int len2 = 0;
        
        while(x)
        {
            len1++;
            x = x>>1;
        }
        
        while(y)
        {
            len2++;
            y = y>>1;
        }
        
        if(len1 != len2)
            return 0;
        
        for(double i = m + 1; i <= n; i++)
        {
            res = res & int(i);
        }
        return res;
    }
};
