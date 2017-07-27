class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
	    int n = nums2.size();
        if(m == 0)
        {
            double res = (n % 2 == 0)?((nums2[n/2]+nums2[n/2-1])/2.0) : nums2[n/2];
            return res;
        }
        else if(n == 0)
        {
            double res = (m % 2 == 0)?((nums1[m/2]+nums1[m/2-1])/2.0) : nums1[m/2];
            return res;
        }
        
        int mid = (nums1.size() + nums2.size()) / 2 + 1;
        vector<int>::iterator it1 = nums1.begin();
	    vector<int>::iterator it2 = nums2.begin();
        
        int cnt = 0;      
        bool flag = ((nums1.size() + nums2.size()) % 2 == 0)? true : false;
	    int fifo[2] = {0, 0};
	    double res;
        
        while (it1 != nums1.end() && it2 != nums2.end())
        {
            if (*it1 > *it2)
		    {
			    cout << *it2 << endl;
			    fifo[0] = fifo[1];
			    fifo[1] = *it2;
			    cnt++;
			    if (cnt == mid)
			    {
				    res = flag?((fifo[0] + fifo[1]) / 2.0) : fifo[1];
				    return res;
			    }
			    it2++;
		    }
		    else
		    {
			    cout << *it1 << endl;
			    fifo[0] = fifo[1];
			    fifo[1] = *it1;
			    cnt++;
			    if (cnt == mid)
			    {
				    res = flag ? ((fifo[0] + fifo[1]) / 2.0) : fifo[1];
				    return res;
			    }
			    it1++;
		    }
        }
        
        if (it1 == nums1.end())
	    {
		    while (it2 != nums2.end())
		    {
			    cout << *it2 << endl;
			    fifo[0] = fifo[1];
			    fifo[1] = *it2;
			    cnt++;
			    if (cnt == mid)
			    {
				    res = flag ? ((fifo[0] + fifo[1]) / 2.0) : fifo[1];
				    return res;
			    }
			    it2++;
		    }
	    }
	    else
	    {
		    while (it1 != nums1.end())
		    {
			    cout << *it1 << endl;
			    fifo[0] = fifo[1];
			    fifo[1] = *it1;
			    cnt++;
			    if (cnt == mid)
			    {
				    res = flag ? ((fifo[0] + fifo[1]) / 2.0) : fifo[1];
				    return res;
			    }
			    it1++;
		    }
	    }
        
        
        
        
    }
};
