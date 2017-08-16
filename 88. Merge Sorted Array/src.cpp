class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);
        nums2.resize(n);
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        if(m == 0 && n == 0)
            return;
        else if(n == 0)
            return;
        else if(m == 0)
        {
            nums1.assign(nums2.begin(), nums2.end());
            return;
        }
            
        int p = 0, q = 0;
        
        while (!nums2.empty())
        {
            if (nums2[q] < nums1[p])
            {
                nums1.insert(nums1.begin(), nums2[q]);
                nums2.erase(nums2.begin());
            }
            else
            {
                bool flag = false;
                for (int i = p + 1; i < nums1.size(); i++)
                {
                    if (nums2[q] <= nums1[i])
                    {
                        nums1.insert(nums1.begin() + i, nums2[q]);
                        nums2.erase(nums2.begin());
                        p = i;
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    nums1.insert(nums1.end(), nums2[q]);
                    nums2.erase(nums2.begin());
                    break;
                }
            }
        }
        
        if (nums2.size())
        {
            nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        }
        
        return;
        
    }
};
