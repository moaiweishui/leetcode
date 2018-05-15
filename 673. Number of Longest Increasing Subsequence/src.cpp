class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return 1;
    
        vector<int> len_v(nums.size(), 1);
        vector<int> cnt_v(nums.size(), 1);

        int max_len = 1;
        int cnt = 1;

        for (int i = 1; i < nums.size(); i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    if (len_v[j] + 1 > len_v[i]){
                        len_v[i] = len_v[j] + 1;
                        cnt_v[i] = cnt_v[j];
                    }
                    else if (len_v[j] + 1 == len_v[i]){
                        cnt_v[i] += cnt_v[j];
                    }
                }
            }
            if (len_v[i] > max_len){
                max_len = len_v[i];
                cnt = cnt_v[i];
            }
            else if (len_v[i] == max_len){
                cnt += cnt_v[i];
            }
        }

        return cnt;
    }
};
