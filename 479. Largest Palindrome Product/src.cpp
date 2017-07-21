#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <time.h>

using namespace std;

int judge = 0;

bool is_Palindrome(int n)
{
	judge++;
	int cnt = 0;
	int tmp = n;
	bool res = true;
	while (tmp)
	{
		tmp = tmp / 10;
		cnt++;
	}

	for (int i = 0; i < (cnt / 2 + cnt % 2); i++)
	{
		int a = pow(10, i);
		int left = n / a % 10;
		int b = pow(10, cnt - 1 - i);
		int right = n / b % 10;
		if (left != right)
		{
			res = false;
			break;
		}

	}
	return res;
}

bool is_Palindrome2(int n)
{
	judge++;
	string s;
	stringstream ss;
	ss << n;
	ss >> s;
	int cnt = s.length();

	bool res = true;

	for (int i = 0; i < (cnt / 2 + cnt % 2); i++)
	{
		if (s[i] != s[cnt - i - 1])
		{
			res = false;
			break;
		}
	}

	return res;
}

void main()
{
	clock_t start, finish;
	start = clock();

	int n = 5;

	int a = (pow(10, n) - 1);
	int b = (pow(10, n) - 1);
	int c = pow(10, n - 1);
	
	
	int res = 0;

	for (int i = a; i >= c; i--)
		for (int j = b; j >= c; j--)
		{
			if (i*j>res && is_Palindrome2(i*j))
				res = i*j;
		}		

	cout << res % 1337 << endl;
	cout << judge << endl;

	finish = clock();

	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << duration << endl;

	return;
}
