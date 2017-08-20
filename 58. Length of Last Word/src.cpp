class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 0)
            return 0;
        int i;
        bool flag = false;
        int r = 0;
        for (i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] == ' ' && !flag)
                r++;
            else if(s[i] != ' ')
                flag = true;
            if (s[i] == ' ' && flag)
                break;
        }
        if(i == -1)
            return s.length() - r;
        else
            return s.length() - i - 1 - r;
    }
};
