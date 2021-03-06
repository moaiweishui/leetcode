/******************* Solution 1 ************************/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int m = nums.size();
        if(m < 4)
        {
            vector<vector<int>> res;
            return res;
        }
        
        vector<int> start_v(m, 0);
        vector<int> end_v(m, 0);
        
        set<vector<int>> combination;
        
        for (int i = 0; i < 4; i++)
        {
            start_v[i] = 1;
            end_v[m - i - 1] = 1;
        }
        int tmp_sum = 0;
        vector<int> tmpv;
        for (int i = 0; i < m; i++)
        {
            if (start_v[i])
            {
                tmpv.push_back(nums[i]);
                tmp_sum += nums[i];
            }
        }
        if (tmp_sum == target)
        {
            sort(tmpv.begin(), tmpv.end());
            combination.insert(tmpv);
        }
        
        while (start_v != end_v)
        {
            for (int i = 0; i < m - 1; i++)
            {
                if (start_v[i] == 1 && start_v[i + 1] == 0)
                {
                    start_v[i] = 0;
                    start_v[i + 1] = 1;

                    int cnt = 0;

                    for (int k = 0; k < i; k++)
                    {
                        cnt += start_v[k];
                        start_v[k] = 0;
                    }

                    for (int k = 0; k < cnt; k++)
                    {
                        start_v[k] = 1;
                    }
                    break;
                }
            }
            tmpv.clear();
            tmp_sum = 0;
            for (int i = 0; i < m; i++)
            {
                if (start_v[i])
                {
                    tmpv.push_back(nums[i]);
                    tmp_sum += nums[i];
                }
            }
            if (tmp_sum == target)
            {
                sort(tmpv.begin(), tmpv.end());
                combination.insert(tmpv);
            }
        }
        vector<vector<int>> res(combination.begin(), combination.end());
        return res;
    }
};


/******************* Solution 1 ************************/
class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int end, int target)
    {
        int left = start;
        int right = end;

        set<vector<int>> res_set;
        vector<int> tmp;

        while (left != right)
        {
            if (nums[left] + nums[right] == target)
            {
                tmp.clear();
                tmp.push_back(nums[left]);
                tmp.push_back(nums[right]);
                res_set.insert(tmp);
                if (left == right - 1)
                    break;
                left++;
                right--;
            }
            else if (nums[left] + nums[right] > target)
            {
                right--;
            }
            else if (nums[left] + nums[right] < target)
            {
                left++;
            }
        }
        vector<vector<int>> res(res_set.begin(), res_set.end());
        return res;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int m = nums.size();
        vector<vector<int>> res;
        if(m < 4)
            return res;

        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> tmpset;
        
        for(int i = 0; i < m - 3; i++)
        {
            for (int j = i + 1; j < m - 2; j++)
            {
                vector<vector<int>> tmpv = twoSum(nums, j+1, m-1, target-nums[i]-nums[j]);
                for (int k = 0; k < tmpv.size(); k++)
                {
                    tmpv[k].insert(tmpv[k].begin(), nums[j]);
                    tmpv[k].insert(tmpv[k].begin(), nums[i]);
                    tmpset.insert(tmpv[k]);
                }           
            }    
        }
        
        res.assign(tmpset.begin(), tmpset.end());
        
        return res;
        
    }
};
