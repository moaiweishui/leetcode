class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1, index2;
        vector<int> res;
        vector<int>::iterator it;
        it = find(numbers.begin() + 1, numbers.end(), target - numbers[0]);
        if (it != numbers.end())
	    {
		    res.push_back(1);
		    res.push_back(it - numbers.begin() + 1);
            return res;
	    }
        int last_val = numbers[0];
        for(int i = 1; i < numbers.size(); i++)
        {
            if(numbers[i] == last_val)
                continue;
            index1 = i;
		    it = find(numbers.begin() + i + 1, numbers.end(), target - numbers[index1]);
		    if (it != numbers.end())
		    {
			    index2 = it - numbers.begin();
			    break;
		    }
        }
        
        
        res.push_back(index1 + 1);
        res.push_back(index2 + 1);
        
        return res;
    }
};
