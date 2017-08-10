class Solution {
public:
    string toHex(int num) {
        unsigned int x;
        if(num < 0)
            x = 0xFFFFFFFF + 1 + num;
        else if(num == 0)
            return "0";
        else
            x = num;
        
        string res = "";
        
        while(x)
        {
            int tmp = x & 15;
            char c;
            if(tmp < 10)
                c = tmp + 48;
            else
                c = tmp + 87;
            
            res = c + res;
            x = x >> 4;
        }
        
        return res;
    }
};
