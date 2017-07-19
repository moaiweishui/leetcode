void main()
{
	vector<vector<int>> nums;

	int n[2][2] = { {1, 2}, { 3, 4 }};

	vector<int> _vec1(n[0], n[0] + 2);
	nums.push_back(_vec1);
	
	vector<int> _vec2(n[1], n[1]+2);
	nums.push_back(_vec2);

	int r = 1, c = 4;

	if (r*c != nums.size()*nums[0].size())
		cout << "Error";
	else
	{

	}

	cout<<nums.size()*nums[0].size();
}
