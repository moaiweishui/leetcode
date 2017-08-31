class Solution {
public:
    bool isPerfectSquare(int num) {
        double i;
        double num_d = num;
        for(i = 0; i <= num; i++)
        {
            if(i*i == num)
                return true;
            else if(i*i > num_d)
                return false;
        }
    }
};
