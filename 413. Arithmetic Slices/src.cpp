/********************** Solution 1 **********************/
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


/********************** Solution 2 **********************/
class Solution {
public:
    int numberOfArithmeticSlicesWithLen(vector<int>& A, int len)
    {
        if(len < 3)
            return 0;
        
        int step = A[len - 1] - A[len - 2];
        int p = len - 3;
        while(p >= 0)
        {
            if(A[p + 1] - A[p] != step)
                break;
            else
                p--;
        }
        
        int depth = len - 2 - p;
        
        if(depth < 2)
            return numberOfArithmeticSlicesWithLen(A, len - 1);
        else
            return depth - 1 + numberOfArithmeticSlicesWithLen(A, len - 1);         
    }
    
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        if(A.size()<3)
        {
            return res;
        }
            
        return numberOfArithmeticSlicesWithLen(A, A.size());

    }
};

/********************** Solution 3 **********************/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
       
        int len = A.size();
        if(len < 3)
            return 0;
            
        vector<int> mem(len, 0);
        
        if(A[0] - A[1] == A[1] - A[2])
            mem[2] = 1;
        
        int step;
        int p, depth;
        for(int i = 3; i < len; i++)
        {
            step = A[i] - A[i - 1];
            p = i - 2;
            while(p >= 0)
            {
                if(A[p + 1] - A[p] != step)
                    break;
                else
                    p--;
            }
            
            depth = i - 1 - p;
            if(depth < 2)
                mem[i] = mem[i - 1];
            else
                mem[i] = depth - 1 + mem[i - 1];
        }

        return mem[len - 1];
    }
};
