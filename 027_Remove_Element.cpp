#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		int marker = -1;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums.at(i) != val)
			{
				marker++;
				nums.at(marker) = nums.at(i);
			}
		}
		return marker+1;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(5);
	//nums.push_back(2);
	//nums.push_back(3);
	
	Solution excalibur;
	int len = excalibur.removeElement(nums, 4);
	cout << len << endl;
	return 0;
}