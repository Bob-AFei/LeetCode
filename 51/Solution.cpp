/*
* @Author: Denghui
* @Date:   2020-12-31 17:14:30
* @Last Modified by:   Denghui
* @Last Modified time: 2020-12-31 17:14:38
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {

private:

	vector <vector <string> > ans;
	int N;

public:

	vector<vector<string>> solveNQueens(int n) 
	{
		// return the answer 
		N = n;

		// number of rest queens
		int res_Q = n;

		// this is the char
		char track [n][n];


		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				track[i][j] = '.';
			}
		}


		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				cout << track[i][j];
			cout << ";" << endl;
		}

		return this->ans;
	}



	bool backtrack(char track, int res_Q, int row)
	{
		if (res_Q == 0)
		{
			save_ans(track);
		}

		for (int col = 0; col < N; ++col)
		{
			if (!isValid(track, row, col))
			{
				continue;
			}

			track[row, col] = 'Q';
			backtrack(track, res_Q-1, row+1);
			track[row, col] = '.';
		}
		return true;
	}




	void save_ans(char track)
	{
		vector <string> one_ans;

		for (int i = 0; i < N; ++i)
		{
			string temp = "";
			for (int j = 0; j < N; ++j)
				temp += track[i][j];
			one_ans.push_back(temp);
		}
		ans.push_back(one_ans);
	}




	bool isValid(char track, int row, int col)
	{
		// check front
		for (int i = row; i >= 0; --i)
		{
			if (track[i][col] == 'Q') return false;
		}


		// check left-front
		for (int i=row,j=col; i>=0,j>=0; --i,--j)
		{
			if (track[i][j] == 'Q') return false;
		}

		// check right-front
		for (int i=row,j=col; i>=0,j<N; --i,++j)
		{
			if (track[i][j] == 'Q') return false;
		}

		return true;
	}




};


int main(int argc, char const *argv[])
{
	Solution().solveNQueens(11);
	return 0;
}