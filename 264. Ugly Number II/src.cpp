class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_nums;
        ugly_nums.push_back(1);
        if (n == 1) return ugly_nums[0];

        int x = 0; 
        int y = 0; 
        int z = 0;

        for (int i = 2; i <= n; i++){
            int min_num = min(2 * ugly_nums[x], min(3 * ugly_nums[y], 5 * ugly_nums[z]));
            if (min_num == 2 * ugly_nums[x]) x++;
            if (min_num == 3 * ugly_nums[y]) y++;
            if (min_num == 5 * ugly_nums[z]) z++;

            ugly_nums.push_back(min_num);
        }
        return ugly_nums[n - 1];
    }
};
