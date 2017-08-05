class Solution {
public:
    struct PairSum{
	    pair<int, int> p;
	    int sum;
	    PairSum(pair<int, int> p) :p(p), sum(){}
    };
    
    static bool cmp(PairSum* x, PairSum* y)
    {   
	    return x->sum < y->sum;
    }
    
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        if(nums1.size() == 0 || nums2.size() == 0)
            return res;      

        vector<PairSum*> v;
        for (int i = 0; i < nums1.size(); i++)
	    {
		    for (int j = 0; j < nums2.size(); j++)
		    {
			    pair<int, int > tmp(nums1[i], nums2[j]);
			    PairSum* ps = new PairSum(tmp);
			    ps->sum = ps->p.first + ps->p.second;
			    v.push_back(ps);
		    }
	    }
        sort(v.begin(), v.end(), cmp);
        
        if(k > v.size())
            k = v.size();
        
        for(int i = 0; i < k; i++)
        {
            res.push_back(v[i]->p);
        }
        
        return res;
    }
};
