class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0)
            return false;
        
        vector<int> candidate;
        candidate.push_back(2);
        candidate.push_back(3);
        candidate.push_back(5);
        
        while(num > 1)
        {
            bool flag = false;
            if(num % 2 == 0)
            {
                flag = true;
                num = num/2;
            }
            if(num % 3 == 0)
            {
                flag = true;
                num = num/3;
            }
            if(num % 5 == 0)
            {
                flag = true;
                num = num/5;
            }   
            if(!flag)
                return false;
        }
        return true;
    }
};
