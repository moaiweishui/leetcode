class Solution {
public:
    int addDigits(int num) {
        if (num / 10 == 0)
		    return num;
	
	    int res = 0;
	    while (num)
	    {
		    res += num % 10;
		    num = num / 10;
	    }
	    return addDigits(res);
    }
};
