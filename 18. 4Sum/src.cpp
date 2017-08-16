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
