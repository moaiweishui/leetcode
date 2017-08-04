class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool res = false;
        if(n <= 2)
            return (n>0) ? true : false;
        while(n % 2 == 0)
        {
            n = n/2;
            if(n == 2)
                return true;
        }
        return res;
    }
};
