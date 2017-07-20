class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int a = nums.size();
		int b = nums[0].size();



		if (r*c != nums.size()*nums[0].size())
		{
			return nums;
		}
		else
		{
			vector<vector<int>> res;
			for (int i = 0; i < r; i++)
			{
				vector<int> _tmp;
				for (int j = 0; j < c; j++)
				{
					_tmp.push_back(nums[(i*c + j) / b][i*c + j) % b]);
				}
				res.push_back(_tmp);
			}
			return res;
		}
	}
};
