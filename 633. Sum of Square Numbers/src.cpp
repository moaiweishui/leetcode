class Solution {
public:
    bool judgeSquareSum(int c) {
        int mid = sqrt(c/2 + 1) + 1;
        for(int i = 0; i <= mid; i++)
        {
            int tmp = sqrt(c - i*i);
            if (tmp*tmp + i*i == c)
                return true;
        }
        return false;
    }
};
