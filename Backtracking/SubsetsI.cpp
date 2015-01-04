#include<vector>

using namespace std;

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > m_res;
        if (nums.size() < 1)
            return m_res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        subsetsHelper(nums, m_res, path, 0);
        return m_res;
    }
    
    void subsetsHelper(const vector<int> &nums, vector<vector<int> > &m_res,
        vector<int> path, int start) {
            m_res.push_back(path);
            for (int i = start; i < nums.size(); i++) {
                path.push_back(nums[i]);
                subsetsHelper(nums, m_res, path, i + 1);
                path.pop_back();
            }
            return ;
        }
};
