class Solution {
public:
    vector<int> constructRectangle(int area) {
        int mid = int(sqrt(area)) + 1;
        int i;
        for(i = mid; i > 0; i--)
        {
            if (area % i == 0)
			    break;
        }
        
        vector<int> res;
        if(area/i > i)
        {
            res.push_back(area/i);
            res.push_back(i);
        }
        else
        {
            res.push_back(i);
            res.push_back(area/i);       
        }
        
        return res;
    }
};
