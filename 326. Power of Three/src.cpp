class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1 or n == 3)
            return true;
        else if(n == 0 or n == 2)
            return false;
        
        bool res = false;
        
        while(n % 3 == 0)
        {
            n = n/3;
            if(n == 3)
                return true;
        }
        return res;
    }
};
