class Solution {
public:
    bool search(vector<int>& nums, int target) {
       if (nums.empty()) return false;
    if (nums.size() == 1) return nums[0] == target;
    
    int left = 0;
    int right = nums.size() - 1;

    int mid;
    while (left < right){
        mid = (left + right) >> 1;
        if (nums[mid] == target) return true;
        if (nums[mid] == nums[left] && nums[mid] == nums[right]){
            left++;
            right--;
        }
        else if (nums[mid] >= nums[left]){  //左边有序
            if (nums[left] <= target && nums[mid] > target){ //target在左边
                right = mid - 1;
            }
            else{  //target在右边
                left = mid + 1;
            }
        }
        else{
            if (nums[right] >= target && nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
    
        return nums[left] == target;
    }
};
