class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 1 or num == 4)
            return true;
        else if(num == 0 or num == 2 or num == 3)
            return false;
        
        bool res = false;
        
        while(num % 4 == 0)
        {
            num = num/4;
            if(num == 4)
                return true;
        }
        return res;
    }
};
