class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int remainLeft = n;
        int remainRight = n;
        vector<string> res;
        string currPar = "";
        generateParenthesis_core(res, currPar, remainLeft, remainRight, 2*n);
        return res;
    }
    
    void generateParenthesis_core(vector<string> &res, string &currPar, int remainLeft, int remainRight, int deep)
    {
        // base case
        if(deep == 0)
        {
            res.push_back(currPar);
            return;
        }
        
        if(remainLeft > 0)
        {
            currPar = currPar + "(";
            generateParenthesis_core(res, currPar, remainLeft-1, remainRight, deep-1);
            currPar.pop_back();
        }
        if(remainRight > remainLeft)
        {
            currPar = currPar + ")";
            generateParenthesis_core(res, currPar, remainLeft, remainRight-1, deep-1);
            currPar.pop_back();
        }
    }
};