class Solution {
public:
    string reverseSingleWord(string s) {
        char *p = &s[0];
        int length = strlen(p);
        
        string res;
        for(int i=0;i<length;i++)
            res += s[length-i-1];
        return res;
    }
    string reverseWords(string s) {
        char* s_p= &s[0];
        string res, tmp_s;
        
        while(1)
        {
            if(*s_p == '\0')
            {
                res += reverseSingleWord(tmp_s);
                tmp_s.clear();
                break;
            }
            else if(*s_p != ' ')
            {
                tmp_s += s_p[0];
            }
            else
            {
                res += reverseSingleWord(tmp_s);
                res += " ";
                tmp_s.clear();
            }
            s_p ++;
        }
        
        return res;
    }
};
