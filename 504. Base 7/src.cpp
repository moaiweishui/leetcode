class Solution {
public:
    string convertToBase7(int num) {
        bool neg_flag = false;
        if(num == 0)
            return "0";
        else if(num < 0)
        {
            neg_flag = true;
            num = -num;
        }
        int bit_width = 0;
        int tmp = num;
        while(num)
        {
            bit_width++;
            num = num / 7;
        }
        int num_7 = 0;
        
        for(int i = bit_width - 1; i >=0; i--)
        {
            num_7 *= 10; 
            int x = tmp / pow(7, i);
            num_7 += x;
            tmp = tmp - pow(7, i) * x;           
        }
        if(neg_flag)
            num_7 = -num_7;
        
        stringstream ss;
        ss << num_7;
        string res;
        ss >> res;
        return res;
    }
};
