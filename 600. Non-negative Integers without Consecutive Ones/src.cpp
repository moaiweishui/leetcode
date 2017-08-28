/***************** Solution 1 *******************/
class Solution {
public:  
    int findIntegers(int num) {
        if(num == 1)
            return 2;
        
        vector<bool> mem(num/2 + 1, false);
        int cnt = 2;
        bool flag;
        for (int i = 2; i <= num; i++)
        {
            flag = false;
            if (mem[i / 2])
                flag = true;
            else if ((i / 2) % 2 == 1 && i % 2 == 1)
                flag = true;
            if (i <= num / 2)
                mem[i] = flag;
            cnt += flag ? 0 : 1;
        }
        
        return cnt;
    }
};
