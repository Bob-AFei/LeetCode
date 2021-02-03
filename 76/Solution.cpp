/*
* @Author: Denghui
* @Date:   2020-12-11 17:14:30
* @Last Modified by:   Denghui
* @Last Modified time: 2021-01-12 15:27:21
*/

#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <unordered_map>

class Solution 
{


private:
	std::unordered_map <char, int> my_map;

	bool isValid (std::unordered_map<char, int>& my_map, std::string t)
	{
		for (char c : t)
		{
			if (my_map[c] < 0)
			{
				return false;
			}
		}
		return true;
	}


public:

	std::string minWindow(std::string s, std::string t) 
	{
		int left = 0;
		int right= 0;

		int ans_left  =  0;
		int ans_right = -1;

		int min_length = INT_MAX;
		std::string target = "";

		for (char c : t)
		{
			my_map[c]--;
		}


		while(right < s.length())
		{
			char c = s[right];
			
			if (my_map.find(c) != my_map.end())
			{
				my_map[c] ++;
				
				if(isValid(my_map, t))
				{
					while(left <= right)
					{
						char _c = s[left];
						if (my_map.find(_c) != my_map.end())
						{ 
							// 无法在减少了
							if (my_map[_c] == 0)
							{
								int cur_length = right-left+1;
								if (cur_length < min_length)
								{
									ans_left   = left;
									ans_right  = right;
									min_length = cur_length;
								}
								break;
							}
							else
							{
								my_map[_c]--;
							}
						}
						left++;
					}
				}
			}
			right++;
		}


		// std::<<c
		for (int i = ans_left; i <= ans_right ; ++i)
		{
			target += s[i];
		}

		return target;
	}
};


int main(int argc, char const *argv[])
{
	std::cout<< Solution().minWindow("ADOBECODEBANC","ABC");
	return 0;
}