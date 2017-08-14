int n = 5;
	vector<vector<int>> res;
	vector<int> tmpv(n, 0);
	for (int i = 0; i < n; i++)	
		res.push_back(tmpv);

	pair<int, int> current_pos(0, 0);
	pair<int, int> end_pos;

	if (n % 2 == 0)
	{
		end_pos.first = n / 2;
		end_pos.second = n / 2 - 1;
	}
	else
	{
		end_pos.first = n / 2;
		end_pos.second = n / 2;
	}

	int ori = RIGHT;
	int cnt = 1;
	while (current_pos != end_pos)
	{
		switch (ori){
			case RIGHT:
				int r = current_pos.first;
				int c = current_pos.second + 1;
				if (r >= 0 && r < n && c >= 0 && c < n && res[r][c] == 0)
				{
					res[r][c] = cnt;
					cnt++;
				}
				else if ()
				
			case DOWN:
			case LEFT:
			case UP:
		}

	}
