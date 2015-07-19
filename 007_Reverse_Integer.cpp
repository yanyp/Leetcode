#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>

using namespace std;


class Solution
{
public:
	int reverse (int x)
	{
		int reverse_x = 0;
		
		// overflow - -2147483648
		if (x != 0 && x != INT_MIN)
		{
			int range = x / abs(x);
			string s = "";
			x = x / range;
			int len = 0;
			while(1)
			{
				if (x == 0)
					break;

				stringstream ss;
				ss << x % 10;
				s = s + ss.str();
			
				x = x / 10;
				len++;
			}

			int factor = 1;
			for (int i = 0; i < len; i++)
			{
				int base = (int) s[len-i-1] - 48;
				
				// overflow
				if ((base * (factor / 10) > INT_MAX / 10) || (INT_MAX - reverse_x < base * factor))
				{
					reverse_x = 0;
					break;
				}
				else
				{
					reverse_x += base * factor;
				}
				factor = factor * 10;
			}
			reverse_x *= range;
		}
		return reverse_x;
	}
};


int main()
{
	Solution excalibur;
	int output = excalibur.reverse(1563847412);
	cout << output << endl;
	return 0;
}