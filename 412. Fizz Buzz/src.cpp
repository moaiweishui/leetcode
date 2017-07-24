class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i = 1; i <= n; i++)
        {
            if((i%5 == 0) && (i%3==0))
                res.push_back("FizzBuzz");
            else if(i%5 == 0)
                res.push_back("Buzz");
            else if(i%3 == 0)
                res.push_back("Fizz");
            else
            {
                stringstream ss;
                string _tmps;
                ss<<i;
                ss>>_tmps;
                res.push_back(_tmps);
            }
        }
        return res;
    }
};
