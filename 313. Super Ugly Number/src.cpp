class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int N = primes.size();
    vector<int> indexs(N, 0);
    
    vector<int> ugly_nums;
    ugly_nums.push_back(1);
    if (n == 1) return ugly_nums[0];

    for (int i = 1; i < n; i++){
        int min = INT_MAX;
        for (int j = 0; j < N; j++){
            if (primes[j] * ugly_nums[indexs[j]] < min){
                min = primes[j] * ugly_nums[indexs[j]];
            }
        }

        for (int j = 0; j < N; j++){
            if (primes[j] * ugly_nums[indexs[j]] == min){
                indexs[j]++;
            }
        }

        ugly_nums.push_back(min);
    }
    return ugly_nums[n - 1];
    }
};
