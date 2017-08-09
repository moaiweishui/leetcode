class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> v(32, 0);
        int cnt = 0;
    	while (n)
	    {
		    v[cnt] = n & 1;
		    cnt++;
		    n = n >> 1;
	    }
        
        unsigned int res = 0;
        
        for (int i = 0; i < 31; i++)
	    {
		    res += v[i];
		    res = res << 1;
	    }
        
        res += v[31];
        
        return res;
    }
};
