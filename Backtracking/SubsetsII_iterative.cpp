#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) { 
        vector<vector<int> > m_res;
        if (S.size() < 1)
            return m_res;
        vector<int> m_s = S;
        sort(m_s.begin(), m_s.end()); 
        vector<int> temp;
        m_res.push_back(temp);
        int curr_size = 0, start_index = 0;
        int prev_value = m_s[0];
        for (int i = 0; i < m_s.size(); i++) {
            curr_size = m_res.size();
            // if curr is differernt from previous value, update start_index and prev_value.
            if (i != 0 && m_s[i] != prev_value) {
                prev_value = m_s[i];
                start_index = 0;
            }
            for (int j = start_index; j < curr_size; j++) {
                temp = m_res[j];
                temp.push_back(m_s[i]);
                m_res.push_back(temp);
                temp.clear();
            }
            start_index = curr_size;
        }
        return m_res;
    }
};

