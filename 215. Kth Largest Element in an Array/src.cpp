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

/************* Solution 3 ***************/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end(), less<int>());
        int res;
        for (int i = 1; i <= k; i++){
            pop_heap(nums.begin(), nums.end());
            res = nums[nums.size() - 1];
            nums.pop_back();
        }
        return res;
    }
};

/************* Solution 4 ***************/
class Solution {
public:
    int partition(vector<int>& nums, int left, int right){
        if (left > right) return -1;
        int base_index = right;
        int parted_index = left - 1;
        for (int i = left; i < right; i++){
            if (nums[i] < nums[base_index]){
                parted_index++;
                if (parted_index != i)
                    swap(nums[parted_index], nums[i]);
            }
        }
        parted_index++;
        if (parted_index != right)
            swap(nums[parted_index], nums[right]);
        return parted_index;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int target_index = nums.size() - k;
        int left = 0;
        int right = nums.size() - 1;
        int index = partition(nums, left, right);
        while (index != target_index){
            if (index > target_index){
                //在左边继续找
                right = index - 1;
                index = partition(nums, left, right);
            }
            else{
                left = index + 1;
                index = partition(nums, left, right);
            }
        }
        return nums[index];
    }
};

/************* Solution 5 ***************/
class Solution {
public:
    void swap(vector<int>& nums, int index1, int index2){
    int temp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
}

void adjust_heap(vector<int>& nums, int parent, int end){
    int temp = nums[parent];
    for (int i = 2 * parent + 1; i <= end; i = i * 2 + 1){
        if (i + 1 <= end && nums[i] < nums[i + 1]){
            i++;
        }
        if (nums[i] > temp){
            nums[parent] = nums[i];
            parent = i;
        }
        else{
            break;
        }
    }
    nums[parent] = temp;
}
    
    int findKthLargest(vector<int>& nums, int k) {
        //构建k次最大堆
    int len = nums.size();
    int start = len / 2 - 1;

    for (int i = start; i >= 0; i--){
        adjust_heap(nums, i, len - 1);
    }
    if (k == 1) return nums[0];
    int cnt = 1;
    for (int i = len - 1; i > 0; i--){
        swap(nums, 0, i);
        adjust_heap(nums, 0, i - 1);
        cnt++;
        if (cnt == k) return nums[0];
    }
    return nums[0];
    }
};
