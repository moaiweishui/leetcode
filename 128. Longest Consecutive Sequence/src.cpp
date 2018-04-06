class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_map<int, bool> hmap;
        for (auto it = nums.begin(); it != nums.end(); it++) hmap[*it] = false;
        int curr;
        int max_len = 1;
        int left, right;
    
        for (auto it = nums.begin(); it != nums.end(); it++){
            curr = *it;
            if (!hmap[curr]){  //unvisited
                int temp_max_len = 1;
                hmap[curr] = true;
                left = curr - 1;
                while (hmap.find(left) != hmap.end()){
                    temp_max_len++;
                    hmap[left] = true;
                    left--;
                }
                right = curr + 1;
                while (hmap.find(right) != hmap.end()){
                    temp_max_len++;
                    hmap[right] = true;
                    right++;
                }
                max_len = max(max_len, temp_max_len);
            }
        }
        return max_len;
    }
};
