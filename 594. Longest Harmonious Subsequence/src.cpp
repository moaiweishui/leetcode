class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        unordered_map<int, int> hmap;
        vector<int> all_nums;
        for (int i = 0; i < nums.size(); i++){
            if (hmap.find(nums[i]) == hmap.end()){
                hmap[nums[i]] = 1;
                all_nums.push_back(nums[i]);
            }
            else{
                hmap[nums[i]]++;
            }
        }

        if (all_nums.size() == 1) return 0;
        int max_len = 0;

        sort(all_nums.begin(), all_nums.end());

        for (int i = 0; i < all_nums.size() - 1; i++){
            if (all_nums[i] + 1 == all_nums[i + 1]){
                if (hmap[all_nums[i]] + hmap[all_nums[i + 1]] > max_len){
                    max_len = hmap[all_nums[i]] + hmap[all_nums[i + 1]];
                }
            }
        }

        return max_len;
    }
};
