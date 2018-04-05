class Solution {
public:
    int binarySearch(vector<int>& nums, int start, int end, int target){
        if (start > end) return -1;
        else if (start == end) return nums[start] == target ? start : -1;
        int mid = (start + end) / 2 + 1;
        if (nums[mid] == target) return mid;
        if (nums[mid] > nums[start]){
            //左边有序
            if (nums[mid] < target) return binarySearch(nums, mid + 1, end, target);
            else{
                int left_res = binarySearch(nums, start, mid - 1, target);
                return left_res == -1 ? binarySearch(nums, mid + 1, end, target) : left_res;
            }
        }
        else{
            //右边有序
            if (nums[mid] > target) return binarySearch(nums, start, mid - 1, target);
            else{
                int right_res = binarySearch(nums, mid + 1, end, target);
                return right_res == -1 ? binarySearch(nums, start, mid - 1, target) : right_res;
            }
        }
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        else if (nums.size() == 1) return nums[0] == target ? 0 : -1;

        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};
