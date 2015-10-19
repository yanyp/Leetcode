class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> currSet;
        subsets_core(res, currSet, nums, 0);
        return res;
    }
    
    void subsets_core(vector<vector<int>>& res, vector<int> currSet, vector<int>& nums, int currIndex)
    {
        if(currIndex == nums.size())
        {
            sort(currSet.begin(), currSet.end());
            res.push_back(currSet);
            return;
        }
        subsets_core(res, currSet, nums, currIndex+1);
        currSet.push_back(nums.at(currIndex));
        subsets_core(res, currSet, nums, currIndex+1);
    }
};