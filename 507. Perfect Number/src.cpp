class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        if(num == 1)
            return false;
        else if(num == 2)
            return false;
        
        int p = 2;
        int end = num/2 + 1;
        while(p < end)
        {
            if(num % p == 0)
            {
                sum += p;
                sum += num / p;
                end = num / p;
            }
            p++;
        }
        
        sum += 1;
        
        return sum == num;
    }
};
