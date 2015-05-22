#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		// sort the given array first
		vector<int> output;
		vector<int> nums_tmp = nums;
		sort(nums.begin(), nums.end());
		
		// check for target with continue/break
		for(int i = 0; i < nums.size() - 1; i++)
		{
			int j = i + 1;
			for(; j < nums.size(); j++)
			{
				if(nums.at(i) + nums.at(j) >= target)
					break;
			}
			
			if(j == nums.size())
				continue;
			else if (nums.at(i) + nums.at(j) == target)
			{
				auto it = find(nums_tmp.begin(), nums_tmp.end(), nums.at(i));
				cout << *it << endl;			
				auto it2 = find(nums_tmp.begin(), nums_tmp.end(), nums.at(j));
				cout << *it2 << endl;
				
				if(*it == *it2)		// repeat element
					it2 = find(it2+1, nums_tmp.end(), nums.at(j));
				
				int index1 = it - nums_tmp.begin() + 1;
				int index2 = it2 - nums_tmp.begin() + 1;
				
				output.push_back(min(index1, index2));
				output.push_back(max(index1, index2));
				break;
			}
		}
		return output;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(-2);
	nums.push_back(-3);
	nums.push_back(-4);
	nums.push_back(-5);
	int target = -8;
	
	Solution excalibur;
	vector<int> index;
	index = excalibur.twoSum(nums, target);
	cout << index.at(0) << '\t' << index.at(1) << endl;
	return 0;
}
