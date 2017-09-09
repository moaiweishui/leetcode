/****************************** Solution 1 *******************************/
class Solution {
public:
    int sumOfSquare(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }
        
    bool isHappy(int n) {
        unordered_set<int> hset;
        pair<unordered_set<int>::iterator, bool> insert_flag;
        int tmp;
        while(1)
        {
            tmp = sumOfSquare(n);
            if(tmp == 1)
                return true;
            insert_flag = hset.insert(n);
            if(!insert_flag.second)
                return false;
            n = tmp;              
        }
        
    }
};

/****************************** Solution 2 *******************************/
class Solution {
public:
    int sumOfSquare(int n)
    {
        int sum = 0;
        int tmp;
        while(n)
        {
            tmp = n % 10;
            sum += tmp * tmp;
            n = n / 10;
        }
        return sum;
    }
        
    bool isHappy(int n) {
        int n_slow = n;
        int tmp;
        bool flag = false;
        while(1)
        {
            if(flag)
            {
                n_slow = sumOfSquare(n_slow);
            }
            n = sumOfSquare(n);
            if(n == 1)
                return true;
            if(n == n_slow)
                return false;
            flag = flag ^ 1;            
        }
        
    }
};
