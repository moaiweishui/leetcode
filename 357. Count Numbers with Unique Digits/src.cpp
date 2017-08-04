class Solution {
public:
    
    int countNumbersWithUniqueDigitsFixedWidth(int n)
    {
        if(n == 1)
            return 10;
        int res = 9;
        for(int i = 1; i < n; i++)
        {
            res *= (10 - i);
        }
        return res;
    }
    
    int countNumbersWithUniqueDigits(int n) {
        if(n > 10)
            return countNumbersWithUniqueDigits(10);
        else if(n == 0)
            return 1;
       
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            res += countNumbersWithUniqueDigitsFixedWidth(i);
        }
        return res;
    }
};
