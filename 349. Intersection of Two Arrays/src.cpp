/******************** Solution 1 *********************/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> res;
        
        for(auto it = set2.begin(); it != set2.end(); it++)
        {
            if(find(set1.begin(), set1.end(), *it) != set1.end())
                res.push_back(*it);
        }
        
        
        return res;
    }
};

/******************** Solution 2 *********************/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
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
                while(nums1[p] == last_num1)
                    p++;
                while(nums2[q] == last_num2)
                    q++;
            }
            else if(nums2[q] > nums1[p])
            {
                last_num1 = nums1[p];
                while(nums1[p] == last_num1)
                    p++;
            }
            else
            {
                last_num2 = nums2[q];
                while(nums2[q] == last_num2)
                    q++;
            }
        }
        
        
        return res;
    }
};
