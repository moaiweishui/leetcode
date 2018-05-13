class Solution {
public:
    bool static cmp(string a, string b){
        return a + b > b + a;
    }

    vector<string> transfer(vector<int>& nums){
        vector<string> output;
        for (int i = 0; i < nums.size(); i++){
            stringstream ss;
            ss << nums[i];
            output.push_back(ss.str());
        }
        return output;
    }
    
    bool check_zero(string s){
        for (int i = 0; i < s.length(); i++){
            if (s[i] != '0') return false;
        }
        return true;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> output = transfer(nums);
        sort(output.begin(), output.end(), cmp);

        string res = "";
        for (int i = 0; i < output.size(); i++){
            res += output[i];
        }
        if (check_zero(res)) return "0";
        else return res;
    }
};
