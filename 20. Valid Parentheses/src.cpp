class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if(len == 0)
            return true;
        else if(len % 2 == 1)
            return false;
        
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < s.length(); i++)
        {
            switch(s[i])
            {
                case ')':
                    if(st.top() == '(')
                        st.pop();
                    else 
                        st.push(s[i]);
                    break;
                    
                case ']':
                    if(st.top() == '[')
                        st.pop();
                    else 
                        st.push(s[i]);
                    break;
                    
                case '}':
                    if(st.top() == '{')
                        st.pop();
                    else 
                        st.push(s[i]);
                    break;
                    
                default:
                    st.push(s[i]);
                    break;
            }
        }
        return st.empty();
    }
};
