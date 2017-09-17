class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if(len == 0)
            return 0;
        
        int l = 0; 
        int r = len - 1;
        int mid;
        while(l <= r)
        {
            mid = (l + r)/2;
            if(len - mid <= citations[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return len - r - 1;
    }
};
