class Solution {
public:
    string reverseString(string s) {
        char *p = &s[0];
        int length = strlen(p);
        
        string res;
        for(int i=0;i<length;i++)
            res += s[length-i-1];
        return res;
    }
};
