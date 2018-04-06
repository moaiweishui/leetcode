class Solution {
public:
    int jump(vector<int>& nums) {
       if (nums.size() <= 1) return 0;
    
        int curr_max = 0;
        int last_max = 0;
        int step = 0;
        for (int i = 0; i < nums.size() - 1; i++){
            curr_max = max(curr_max, i + nums[i]);
            if (i == last_max){
                last_max = curr_max;
                step++;
            }
        }

        return step;
    }
};
