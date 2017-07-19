class Solution {
public:
    int findComplement(int num) {
        int a = num;
        int b = 0;
        while(a)
        {
            b = (b << 1) + 1;
            a = a >> 1;
        }
        
        return num ^ b;
    }
};
