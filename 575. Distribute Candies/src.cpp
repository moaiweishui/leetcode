#include <stdio.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;


int distributeCandies(vector<int>& candies) {
	vector<int>::iterator it;
	vector<int> _vec;
	for (it = candies.begin(); it != candies.end(); it++)
	{
		vector<int>::iterator _it;
		_it = find(_vec.begin(), _vec.end(), *it);
		if (_it == _vec.end())
		{
			_vec.push_back(*it);
		}
	}

	int res = candies.size() / 2;
	if (_vec.size()<res)
		return _vec.size();
	else
		return res;
}

int distributeCandies2(vector<int>& candies)
{
	sort(candies.begin(), candies.end());
	vector<int>::iterator it;
	int tmp = *candies.begin();
	int cnt = 1;
	for (it = candies.begin(); it != candies.end(); it++)
	{
		if (*it != tmp)
		{
			cnt++;
			tmp = *it;
		}

	}
	
	int res = candies.size() / 2;
	if (cnt < res)
		return cnt;
	else
		return res;
}

void main(){
	clock_t start, finish;
	start = clock();

	int num = 5888;
	int a = num, cnt = 0;

	int n[] = { 1, 1, 1, 1, 3, 3};

	vector<int> candies(n, n + 6);

	//distributeCandies2(candies);

	cout << distributeCandies2(candies) << endl;

	finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f seconds\n", duration);
	return;
}
