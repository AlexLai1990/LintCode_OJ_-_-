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
        sort(nums.begin(), nums.end());
        vector<int> temp;
        m_res.push_back(temp);
        int curr_size = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr_size = m_res.size();
            for (int j = 0; j < curr_size; j++) {
                temp = m_res[j];
                temp.push_back(nums[i]);
                m_res.push_back(temp);
                temp.clear();
            }
        }
        return m_res;
    }
};
