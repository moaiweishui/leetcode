/************************* Solution 1 ****************************/
class Solution {
public:
    void quickSort(vector<int>& nums, int left, int right)
    {
        if(left < right)
        {
            int i = left, j = right;
            int x = nums[left];
            
            while(i < j)
            {
                while (i < j && nums[j] > x)
                    j--;
                if(i < j)
                {
                    nums[i] = nums[j];
                    i++;
                }
                while(i < j && nums[i] < x)
                    i++;
                if(i < j)
                {
                    nums[j] = nums[i];
                    j--;
                }
            }
            nums[i] = x;
            quickSort(nums, left, i-1);
            quickSort(nums, i+1, right);
        }
        
    }
    
    void sortColors(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 0)
            return;
        quickSort(nums, 0, nums.size() - 1);
    }
};


/************************* Solution 2 ****************************/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return;
        
        int r = 0, w = 0, b = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                r++;
            else if(nums[i] == 1)
                w++;
            else
                b++;
        }
        int p = 0;
        while(r)
        {
            nums[p] = 0;
            r--;
            p++;
        }
        while(w)
        {
            nums[p] = 1;
            w--;
            p++;
        }
        while(b)
        {
            nums[p] = 2;
            b--;
            p++;
        }
    }
};

/************************* Solution 3 ****************************/
class Solution {
public:
    void swap(vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void sortColors(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return;
        
        int left = -1;
        int right = nums.size();
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (i == left + 1)
                    left++;
                else if (i > left + 1)
                {
                    swap(nums, left + 1, i);
                    left++;
                }
            }
            else if (nums[i] == 2)
            {
                if (i == right - 1)
                    right--;
                else if (i < right - 1)
                {
                    if (nums[right - 1] == 1)
                    {
                        swap(nums, i, right - 1);
                        right--;
                    }
                    else if (nums[right - 1] == 0)
                    {
                        swap(nums, i, right - 1);
                        right--;
                        swap(nums, i, left + 1);
                        left++;
                    }
                    else
                    {
                        right--;
                        i--;
                    }
                }
            }
            if (i == right)
                break;
        }
    }
};
