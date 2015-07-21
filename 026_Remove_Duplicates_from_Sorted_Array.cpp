#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		int marker = -1;
		if(nums.size() != 0)
		{
			marker++;
			for(int i = 1; i < nums.size(); i++)
			{
				if(nums.at(i) != nums.at(i-1))
				{
					marker++;
					nums.at(marker) = nums.at(i);
				}
			}
		}
		return marker+1;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	
	Solution excalibur;
	int len = excalibur.removeDuplicates(nums);
	cout << len << endl;
	return 0;
}