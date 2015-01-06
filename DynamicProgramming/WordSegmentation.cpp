class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    
    bool wordSegmentation(string s, unordered_set<string> &dict) {
        if (s.length() == 0 && dict.size() == 0)
    		return true;
    	if (s.length() < 1 || dict.size() < 1)
    		return false;
        int max_len = 0;
    	for (auto item : dict) {
		    if (item.length() > max_len)
			max_len = item.length();
	    }
    	int n = s.length();
    	vector<bool> m_break(n + 1, false);
    	m_break[0] = true;
	    for (int i = 1; i <= n; i++) {
    		for (int j = max(0, i - max_len); j < i; j++) { 
    			if (m_break[j] && (dict.find(s.substr(j, i - j)) != dict.end())) {
    				m_break[i] = true;
    				break;
    			}
    		}
    	}
    	return m_break[n]; 
    }

};
