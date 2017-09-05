class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x < 10)
            return true;
        
        int num = x;
        int len = 0;
        while(num)
        {
            len++;
            num = num/10;
        }
        
        int r = 0;
        int rlen = len / 2;
        while(rlen)
        {
            r = r * 10 + x % 10;
            rlen--;
            x = x / 10;
        }

        //cout<<r<<'-'<<x<<endl;
        if(len % 2 == 0)
            return r == x;
        else
            return r == x/10;
    }
};
