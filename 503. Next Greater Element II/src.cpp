class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
	    {
		    if (i == 0)
		    {
			    int tmp = -1;
			    for (int j = 1; j < nums.size(); j++)
			    {
				    if (nums[j] > nums[i])
				    {
					    tmp = nums[j];
					    break;
				    }
			    }
			    res.push_back(tmp);
		    }
		    else if (i == nums.size() - 1)
		    {
			    int tmp = -1;
			    for (int j = 0; j < nums.size() - 1; j++)
			    {
				    if (nums[j] > nums[i])
				    {
					    tmp = nums[j];
					    break;
				    }
			    }
			    res.push_back(tmp);
		    }
		    else
		    {
			    int tmp = -1;
			    bool flag = false;
			    for (int j = i + 1; j < nums.size(); j++)
			    {
				    if (nums[j] > nums[i])
				    {
					    tmp = nums[j];
					    flag = true;
					    break;
				    }
			    }
			    if (!flag)
			    {
				    for (int j = 0; j < i; j++)
				    {
					    if (nums[j] > nums[i])
					    {
						    tmp = nums[j];
						    flag = true;
						    break;
					    }
				    }
			    }
			    res.push_back(tmp);
		    }
	    }
        return res;
    }
};
