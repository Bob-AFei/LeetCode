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


	vector <string> initial_ans (int n)
	{
		string temp = "";
		for (int i = 0; i < n; ++i)
		{
			temp += '.';
		}


		vector <string> single_ans; 

		for (int i = 0; i < n; ++i)
		{
			single_ans.push_back(temp);
		}

		return single_ans;
	}


	// 检查目前的解决方案是否合法
	bool is_valid(vector<string> single_ans, int row, int col, int total)
	{
		// 检查上方
		for (int i = row-1; i>=0 ; --i)
		{
			if (single_ans.at(i)[col] == 'Q')
				return false;
		}

		// 检查左上
		for (int i=row-1,j=col-1; i>=0&&j>=0; --i,--j)
		{
			if(single_ans.at(i)[j] == 'Q')
				return false;
		}

		// 检查右上
		for (int i=row-1,j=col+1; i>=0&&j<total; --i,++j)
		{

			cout << i << "TEST" << j << endl;
			if(single_ans.at(i)[j] == 'Q')
				return false;
		}

		return true;
	}




	void backtrack (vector <string> single_ans, int resQ,int row,int total)
	{
		if (resQ == 0)
		{
			ans.push_back(single_ans);
			return;
		}

		for (int col = 0; col < total; ++col)
		{
			
			// 如果不合法，直接进行下一轮实验
			if (! is_valid(single_ans, row, col, total))
			{
				continue;
			}
			// 如果合法，检查下一行
			else
			{
				single_ans.at(row)[col] = 'Q';
				backtrack(single_ans,resQ-1, row+1,total);
				// 完成后撤销选择
				single_ans.at(row)[col] = '.';
			}
		}
	}



	void check_answer()
	{
		for (vector <string> single_ans:  ans)
		{
			for (string _ans : single_ans)
			{
				cout << _ans << endl;
			}
			cout << endl;
		}
	}



public:
	vector <vector <string> > solveNQueens(int n)
	{
		vector <string> single_ans = initial_ans(n);
		// 还剩余这么多个皇后
		int resQ = n;
		// 目前在第几层
		int row  = 0;

		backtrack (single_ans, resQ, row, n);
		
		// check_answer();
		return ans;
	}
};




// int main(int argc, char const *argv[])
// {
// 	Solution().solveQueens(5);
// 	return 0;
// }