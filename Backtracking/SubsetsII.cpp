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
        vector<int> path;
        subsetsWithDupHelper(m_s, m_res, path, 0);
        return m_res;
    }
    
    void subsetsWithDupHelper(const vector<int> &S, vector<vector<int> > &m_res, 
        vector<int> path, int start) {
        m_res.push_back(path);
        for (int i = start; i < S.size(); i++) {
            while (i > start && i < S.size() && S[i] == S[i - 1])
                i++;
            if (i < S.size()) {
                path.push_back(S[i]);
                subsetsWithDupHelper(S, m_res, path, i + 1);
                path.pop_back();
            }
        }
        return;
    }
};

