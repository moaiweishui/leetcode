class Solution {
public:
    void searchStart(vector<int>& nums, int target, int start, int end, vector<int>& res) 
    {
        if(start > end)
            return;
        else if(nums[end] < target)
            return;
        else if(nums[start] > target)
            return;

        int mid = (start + end) / 2;
        if(nums[mid] == target)
        {
            if(mid == start)
            {
                res[0] = start;
                return;
            }
            else if(nums[mid - 1] == target)
                searchStart(nums, target, start, mid - 1, res);
            else
            {
                res[0] = mid;
                return;
            }
        }
        else if(nums[mid] > target)
            searchStart(nums, target, start, mid - 1, res);
        else
            searchStart(nums, target, mid + 1, end, res);
    }
    
    void searchEnd(vector<int>& nums, int target, int start, int end, vector<int>& res) 
    {
        if(start > end)
            return;
        else if(nums[end] < target)
            return;
        else if(nums[start] > target)
            return;
        
        int mid = (start + end) / 2;
        
        if(nums[mid] == target)
        {
            if(mid == end)
            {
                res[1] = end;
                return;
            }
            else if(nums[mid + 1] == target)
                searchEnd(nums, target, mid + 1, end, res);
            else
            {
                res[1] = mid;
                return;
            }
                
        }
        else if(nums[mid] > target)
            searchEnd(nums, target, start, mid - 1, res);
        else
            searchEnd(nums, target, mid + 1, end, res);
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.size() == 0)
            return res;
        searchStart(nums, target, 0, nums.size() - 1, res);
        int start = (res[0] == -1) ? 0 : res[0];
        searchEnd(nums, target, res[0], nums.size() - 1, res);
        return res;
    }
};
