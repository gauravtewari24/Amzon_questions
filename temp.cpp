// C++ implementation to find k numbers with most
// occurrences in the given array
#include <bits/stdc++.h>

using namespace std;

bool condition(char ar[3][3])
{
	int j = 0;
	if (ar[0][0] == ar[1][1] && ar[1][1] == ar[2][2] && ar[0][0] != '.')
		return true;
	else if (ar[2][0] == ar[1][1] && ar[1][1] == ar[2][0] && ar[2][0] != '.')
		return true;

	for (int i = 0; i < 3; i++)
	{
		int row = 0, col = 0;
		for (int j = 1; j < 3; j++)
		{
			if (ar[i][j] == '.')
			{
				row = 1;
				break;
			}
			if (ar[i][j] != ar[i][j - 1])
				row = 1;
		}
		for (int j = 1; j < 3; j++)
		{
			if (ar[j][i] == '.')
			{
				col = 1;
				break;
			}
			if (ar[j][i] != ar[j - 1][i])
				col = 1;
		}
		if (row == 0 || col == 0)
			return true;
	}

	return false;
}

void show(char ar[3][3])
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << ar[i][j] << " | ";
		}
		cout << "\n";
	}
}

// Driver program to test above
int main()
{
	char ar[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ar[i][j] = '.';
		}
		cout << "\n";
	}
	show(ar);
	int cnt = 1;
	bool win = true;
	do
	{
		cout << "Enter your Choice ((1 1),(1 2),..(2 3)....) : ";
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (cnt % 2 != 0)
		{
			ar[a][b] = 'X';
			if (condition(ar))
				cout << "Player 1 wins \n", win = false;
		}
		else
		{
			ar[a][b] = 'O';
			if (condition(ar))
				cout << "Player 2 wins \n", win = false;
		}
		show(ar);
		cnt++;
		if (cnt > 8)
			cout << "No Player Wins \n", win = false;
	} while (win);
}
