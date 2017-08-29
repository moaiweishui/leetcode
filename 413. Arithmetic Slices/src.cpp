class Solution {
public:
    bool isArithmeticSlices(vector<int>& input)
    {
        bool res = true;
        int step = input[1] - input[0];
        int x = input[1] + step;
        for(int i = 2; i<input.size(); i++)
        {
            if(x != input[i])
            {
                res = false;
                break;
            }
            else
            {
                x += step;
            }
        }
        
        return res;
    }
    
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        if(A.size()<3)
        {
            return res;
        }
            
        //vector<bool> flagv(A.size(), true);
        for(int i =0; i < A.size() - 2; i++)
        {
            for(int j = 3; j <= A.size() - i; j++)
            {
                vector<int> tmp(A.begin() + i, A.begin() + i + j);
                if(isArithmeticSlices(tmp))
                {
                    res++;
                }
                else
                    break;
            }
        }
        return res;
    }
};
