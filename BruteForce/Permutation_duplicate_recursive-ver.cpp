#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) { 
        vector<vector<int> > m_res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        permuteHelper(nums, path, m_res, 0);
        return m_res;
    } 
	
    void permuteHelper(vector<int> &nums, vector<int> path, vector<vector<int> > &m_res, int start) {
        if (start == nums.size()) {
            m_res.push_back(path);
            return;
        } 
        for (int i = start; i < nums.size(); i++) { 
            if (!needForSwitch(nums, start, i, nums[i]))
                continue;
            path.push_back(nums[i]);
            swap(nums[start], nums[i]);
            permuteHelper(nums, path, m_res, start + 1);
            swap(nums[start], nums[i]);
            path.pop_back();
        }
        return;        
    } 
	
    bool needForSwitch(const vector<int> &nums, int start, int end, int check) { 
        for (int i = start; i < end; i++) {
            if (check == nums[i])
                return false;
        }
        return true;
    }
    
};
