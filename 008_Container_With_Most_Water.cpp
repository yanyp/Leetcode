#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		// initialization
		int maxWater = 0, currWater;
		if(height.size() > 1)
		{
			int head = 0;
			int tail = height.size() - 1;
			maxWater = (tail - head) * min(height.at(tail), height.at(head));
			
			while(head < tail)
			{
				if(height.at(head) < height.at(tail))
				{
					head++;
				}
				else
				{
					tail--;
				}
				currWater = (tail - head) * min(height.at(tail), height.at(head));
				maxWater = max(maxWater, currWater);
			}
		}
		return maxWater;
	} 
};

int main()
{
	vector<int> height;
	height.push_back(2);
	height.push_back(5);
	height.push_back(3);
	height.push_back(1);
	
	Solution excalibur;
	int maxWater = excalibur.maxArea(height);
	cout << maxWater << endl;
	return 0;
}