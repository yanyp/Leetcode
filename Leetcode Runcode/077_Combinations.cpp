class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> currSelect;
        vector<bool> boolSelect;
        for(int i = 0; i < n; i++)
        {
            boolSelect.push_back(false);
        }
        combine_core(res, boolSelect, currSelect, n, k);
        return res;
    }
    
    void combine_core(vector<vector<int>> &res, vector<bool> boolSelect, vector<int> currSelect, int n, int remain)
    {
        // base case
        if(remain == 0)
        {
            res.push_back(currSelect);
            return;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(boolSelect.at(i) == false)
            {
                currSelect.push_back(i+1);
                boolSelect.at(i) = true;
                combine_core(res, boolSelect, currSelect, n, remain-1);
                currSelect.pop_back();
                // no need to update boolSelect
            }
        }
    }
};