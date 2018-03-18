class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hash_table;
    
        for (int i = 0; i < nums.size(); i++){
            auto it = hash_table.find(target - nums[i]);
            if (it != hash_table.end()){
                if (hash_table[target - nums[i]] < i){
                    res.push_back(hash_table[target - nums[i]]);
                    res.push_back(i);
                    break;
                }
            }
            else{
                hash_table[nums[i]] = i;
            }
        }
        return res;
    }
};
