class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        vector<int> res;
        
        if(len1 == 0 || len2 == 0)
            return res;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
              
        int p = 0, q = 0;
        int last_num1, last_num2;
        
        while(p < len1 && q < len2)
        {
            if(nums2[q] == nums1[p])
            {
                res.push_back(nums2[q]);
                last_num1 = nums1[p];
                last_num2 = nums2[q];
                p++;
                q++;
            }
            else if(nums2[q] > nums1[p])
            {
                p++;
            }
            else
            {
                q++;
            }
        }
        
        
        return res;
    }
};
