class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) { 
        vector<string> m_ret;
        unordered_map<int, vector<string> > m_dict;
        int hash = 0;
        for (int i = 0; i < strs.size(); i++) {
            hash = getHashValue(strs【i】);
            if (m_dict.find(hash) == m_dict.end()) {
                vector<string> m_new_vec;
                m_dict[hash] = m_new_vec;
            }
            m_dict[hash].push_back(strs【i】);
        }
        for (auto it = m_dict.begin(); it != m_dict.end(); it++) {
            if (it->second.size() > 1) {
                for (int i = 0; i < it->second.size(); i++) {
                    m_ret.push_back(it->second【i】);
                }
            }
        }
        return m_ret;
    }
    
    int getHashValue(const string &s) {
        vector<int> m_count(26, 0);
        for (int i = 0; i < s.length(); i++) {
            m_count[s【i】 - 'a']++;
        }
        int hash_size = INT_MAX;
        long m_res = 0;
        for (int i = 0; i < m_count.size(); i++) {
            m_res = m_res * 33 + m_count【i】;
            m_res %= hash_size;
        }
        return (int)m_res;
    }
};