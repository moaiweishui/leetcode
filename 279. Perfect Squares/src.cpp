class Solution {
public:
    int numSquaresWithMem(int n, vector<int>& nums, int len, vector<vector<short>>& mem)
    {
        if(n == 0)
            return 0;
        if(len == 1)
            return n;
        
        if(mem[len - 2][n] == -1)
            mem[len - 2][n] = numSquaresWithMem(n, nums, len - 1, mem);
        
        if(n - nums[len - 1] < 0)
            return int(mem[len - 2][n]);
        else
        {
            if(mem[len - 1][n - nums[len - 1]] == -1)
                mem[len - 1][n - nums[len - 1]] = numSquaresWithMem(n - nums[len - 1], nums, len, mem);
        
            return int(min( int(mem[len - 2][n]), int(mem[len - 1][n - nums[len - 1]] + 1) ));
        }    
    }
    
    int numSquares(int n) {
        if(n < 4)
            return n;
        
        vector<int> nums;
        for(int i = 1; i < n; i++)
        {
            if(i * i > n)
                break;
            else
                nums.push_back(i * i);
        }
        
        int len = nums.size();
        
        vector<short> rowv(n + 1, -1);
        vector<vector<short>> mem;
        
        for(int i = 0; i < len; i++)
        {          
            mem.push_back(rowv);
            mem[i][0] = 0;
        }
        for(int i = 0; i <= len; i++)
            mem[0][i] = i;
            
        
        return numSquaresWithMem(n, nums, len, mem);
    }
};
