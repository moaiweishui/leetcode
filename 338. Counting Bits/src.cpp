class Solution {
public:
    int bit_num(int a){
	    int res = 0;
	    while (a){
		    res += a & 1;
		    a = a >> 1;
	    }
	    return res;
    }
    vector<int> countBits(int num) {
        vector<int> v;
        for (int i = 0; i <= num;i++){
		v.push_back(bit_num(i));
	    }
        return v;
    }
};
