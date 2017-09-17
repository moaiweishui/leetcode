class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if(len == 0)
            return 0;
        
        sort(citations.begin(), citations.end());
        
        int res;
        
        for(int i = len; i > 0; i--)
        {
            if(i <= citations[len - i])
            {
                res = i;
                break;
            }
        }
        
        return res;
    }
};
