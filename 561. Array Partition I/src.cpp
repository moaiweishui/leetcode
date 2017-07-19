#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

void exchange(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;

	return;
}

void bubble_sort(vector<int> &num)
{
	int num_size = num.size();
	for (int i = 0; i < num_size - 1; i++)
		for (int j = 0; j < num_size - 1 - i;j++)
			if (num[j] > num[j + 1])
				exchange(num[j], num[j + 1]);
	return;
}

void quick_sort(vector<int> &num, int left, int right)
{
	if (left < right)
	{
		int _left = left;
		int _right = right;
		int p = num[left];
		while (_left < _right)
		{
			while (_right)
			{
				if (num[_right] < p)
				{
					num[_left] = num[_right];
					break;
				}
				_right--;
			}

			while (_left < _right)
			{
				if (num[_left] > p)
				{
					num[_right] = num[_left];
					break;
				}
				_left++;
			}

			num[_left] = p;
		}

		quick_sort(num, left, _left - 1);
		quick_sort(num, _left + 1, right);
	}
	return;
}

void merge_array(vector<int> &num, int left, int mid, int right, vector<int> &tmp)
{
	int p1 = left;
	int p2 = mid + 1;
	int k = 0;
	while (p1 <= mid && p2 <= right)
	{
		if (num[p1] <= num[p2])
			tmp[k++] = num[p1++];
		else
			tmp[k++] = num[p2++];
	}

	while (p1 <= mid)
		tmp[k++] = num[p1++];
	while (p2 <= right)
		tmp[k++] = num[p2++];

	for (int i = 0; i < k; i++)
		num[left + i] = tmp[i];
}

void merge_sort(vector<int> &num, int left, int right, vector<int> &tmp)
{
	//int n = num.size();
	if (left < right)
	{
		//切分
		int mid = (left + right) / 2;
		//左边归并排序
		merge_sort(num, left, mid, tmp);
		//右边归并排序
		merge_sort(num, mid + 1, right, tmp);
		//merge
		merge_array(num, left, mid, right, tmp);
	}
	return;
}


void main()
{
	//int n[] = {1, 3, 2, 4};
	int n[] = { 6, 1, 27, 9, 3, 4, 5, 10, 8, 2 };
	int num_size = sizeof(n) / sizeof(n[0]);
	
	vector<int> num(n, n + num_size);

	//冒泡排序
	//bubble_sort(num);

	//快速排序
	//quick_sort(num, 0, num_size - 1);

	//归并排序
	//这里的tmp用于归并排序过程中的统一临时存储
	//也可以在merge_array()内部，每次临时new一个临时数组作为存储，优点是比较清晰，缺点是多次递归时执行多次new的过程比较耗费时间
	vector<int> tmp(num_size);
	merge_sort(num, 0, num_size - 1, tmp);
	
	int res=0;
	for (int i = 0; i < num.size(); i=i+1)
	{
		printf("%d\n", num[i]);
		res += num[i];
	}
	printf("%d\n", res);
	
}
