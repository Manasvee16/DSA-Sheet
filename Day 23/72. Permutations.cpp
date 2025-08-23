class Solution 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums); //first permutation
        while (next_permutation(nums.begin(), nums.end()))
        {
                ans.push_back(nums);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;        // collects all complete permutations
        vector<int> path;               // current permutation being built
        vector<int> used(nums.size(), 0); // used[i] == 1 means nums[i] is already in 'path'
        dfs(nums, path, used, ans);     // start recursive construction from empty path
        return ans;                     // return all generated permutations
    }
    // Recursively build permutations by trying all unused elements at the next position.
    void dfs(const vector<int>& nums, vector<int>& path, vector<int>& used, vector<vector<int>>& ans) {
        if (path.size() == nums.size()) { // base case: a full-length permutation is formed
            ans.push_back(path);          // store a copy of the current permutation
            return;                       // backtrack
        }
        for (int i = 0; i < (int)nums.size(); ++i) { // try to place each element at the next position
            if (used[i]) 
                continue;        // skip if nums[i] is already used in 'path'
            used[i] = 1;                  // choose: mark nums[i] as used
            path.push_back(nums[i]);      // choose: append nums[i] to the current path
            dfs(nums, path, used, ans);   // explore: recurse to fill the next position
            path.pop_back();              // undo: remove nums[i] from the path
            used[i] = 0;                  // undo: mark nums[i] as unused again
        }
    }
};
