class Solution {
public:
    bool isValid(int n, string& mem)
    {
        int sum = 0;
        for(int i = 0; i < mem.length(); i++)
            sum += int(mem[i]) - 40;
        if(sum > mem.length()/2)
            return false;
        else if(mem.length() > n && sum < mem.length() - n)
            return false;
        else
            return true;
    }
    
    void generateParenthesisWithMem(int n, vector<string>& res, string& mem)
    {
        if(mem.length() == 2*n)
        {
            res.push_back(mem);
            return;
        }
        
        for(int i = 0; i <= 1; i++)
        {
            string temps = mem + char(40 + i);
            if(isValid(n, temps))
            {
                mem = temps;
                generateParenthesisWithMem(n, res, mem);
                mem.erase(mem.end() - 1);
            }
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string mem = "";
        generateParenthesisWithMem(n, res, mem);
        return res;
    }
};
