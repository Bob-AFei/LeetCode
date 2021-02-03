<<<<<<< HEAD

#include <vector>
#include <string>

using namespace std;



class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        return 0;
    }
};
=======
/*
* @Author: Denghui
* @Date:   2020-01-8 15:14:30
* @Last Modified by:   Denghui
* @Last Modified time: 2021-01-08 17:02:29
*/


#include <vector>
#include <set>
#include <string>
#include <climits>
#include <iostream>

using namespace std;

class Solution {

private:
	int min_step = 0;

	char sub(char a)
	{
		if (a =='0') return '9';
		return a-1;
	}

	char add(char a)
	{
		if (a == '9') return '0';
		return a+1;
	}


	bool BFS (vector <string>& this_round, set <string>& visited, vector <string>& deadends, string target)
	{
		vector <string> next_round;

		if (this_round.empty()) return false;


		for (string current : this_round)
		{
			if (isDead(current, deadends)) continue;

			if (current == target)
				return true;

			for (string poss : find_possible(current))
			{
				if (visited.count(poss) == 0)
				{
					visited.insert(poss);
					next_round.push_back(poss);
				}
			}
		}

		min_step ++;
		return BFS(next_round, visited, deadends, target);
	}


	bool isDead (string current, vector <string>& deadends)
	{
		for (string deadend:deadends)
			if (current == deadend)
				return true;
		return false;
	}



	vector <string> find_possible(string current)
	{
		vector <string> possibilities;
		string temp;

		for (int i = 0; i < 4; ++i)
		{
			temp = current;
			temp[i] = sub(temp[i]);
			possibilities.push_back(temp);
			temp = current;
			temp[i] = add(temp[i]);
			possibilities.push_back(temp);
		}
		return possibilities;
	}



public:

	int openLock(vector<string>& deadends, string target) 
	{
		set <string> visited;
		vector <string> next_round;

		next_round.push_back("0000");
		if (BFS(next_round, visited, deadends, target)) return min_step;
		return -1;
	}

};


int main(int argc, char const *argv[])
{
	vector <string> deadends;
	deadends.push_back("0000");

	string target = "8888";
	cout << Solution().openLock(deadends, target) << endl;

	return 0;
}
>>>>>>> 4b6819a534329083fb13f4429e3ba7fe20c8d49a
