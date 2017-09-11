class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 0;
        int pos = digits.size() - 1;
        
        int sum = digits[pos] + 1;
        if(sum == 10)
        {
            sum = 0;
            c = 1;
        }
        digits[pos] = sum;
        pos--;
        
        while(c == 1 && pos >= 0)
        {
            sum = digits[pos] + 1;
            if(sum == 10)
            {
                sum = 0;
                c = 1;
            }
            else
                c = 0;
            digits[pos] = sum;
            pos--;
        }
        
        if(pos < 0 && c == 1)
        {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
