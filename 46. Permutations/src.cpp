string x = "123";

	while (x != "321")
	{
		int p = 0;
		for (int i = x.length() - 2; i >= 0; i--)
		{
			if (x[i] < x[i + 1])
			{
				p = i;
				char tmp = x[i + 1];
				int tmp_index = i + 1;
				for (int j = i + 1; j < x.length(); j++)
				{
					if (x[j] > x[i] && x[j] < tmp)
					{
						tmp = x[j];
						tmp_index = j;
					}
				}
				swap(x, i, tmp_index);
				reverse(x.begin() + i + 1, x.end());
				cout << x << endl;
				break;
			}
		}
	}
