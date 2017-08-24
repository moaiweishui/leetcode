/************* Solution 1 ***************/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

/************* Solution 2 ***************/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> q(nums.begin(), nums.end());
        
        for(int i = 0; i < k; i++)
        {
            if(i == k - 1)
                return q.top();
            else
                q.pop();
        }
        
    }
};
