class Solution {
public:
    
    bool is_sorted(vector<int>& v)
    {
	    bool res = true;
	    for (int i = 0; i < v.size() - 1; i++)
	    {
		    if (v[i] > v[i + 1])
		    {
			    res = false;
			    break;
		    }
	    }
	    return res;
    }
    
    static bool cmp(int& x, int& y)
    {
	    return x > y;
    }
    
    int nextGreaterElement(int n) {
        
	    vector<int> nums;

	    while (n != 0)
	    {
		    nums.push_back(n % 10);
		    n = n / 10;
	    }
        if(nums.size() == 1)
            return -1;
        
        if(is_sorted(nums))
            return -1;
        
        int min = 0x7FFFFFFF;
	    int index;
        
        for (int i = 2; i <= nums.size(); i++)
	    {
		    vector<int> v(nums.begin(), nums.begin() + i);
		    bool tmp_flag;
		    tmp_flag = is_sorted(v);
		    if (!tmp_flag)
		    {
			    cout << i << endl;

			    for (int j = 0; j < i - 1; j++)
			    {
				    if (v[j]<min && v[j]>v[i - 1])
				    {
					    min = v[j];
					    index = j;
				    }
			    }

			    int tmp = nums[i - 1];
			    nums[i - 1] = nums[index];
			    nums[index] = tmp;
			    sort(nums.begin(), nums.begin()+i-1, cmp);
			    break;
		    }
	    }
        
        double res = 0;
        for (int i = 0; i < nums.size(); i++)
	    {
		    res += nums[i] * pow(10, i);
	    }
        if(res > 0x7FFFFFFF)
            return -1;
        else
            return int(res);
    }
};
