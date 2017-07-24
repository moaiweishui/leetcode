class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        vector<int>::iterator it;
        
        for(it = findNums.begin(); it< findNums.end(); it++)
        {
            vector<int>::iterator find_result = find(nums.begin( ), nums.end( ), *it);
            bool flag = false;
		    vector<int>::iterator it2;
            
            for (it2 = find_result+1; it2 < nums.end(); it2++)
		    {
			    if (*it2>*find_result)
			    {
			    	flag = true;
				    break;
			    }
			    cout << *it2 << endl;
		    }
            if(flag)
                res.push_back(*it2);
            else
                res.push_back(-1);
            
        }
        
        return res;   
    }
};
