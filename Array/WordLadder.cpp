class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        if (start == end)
            return 0;
        queue<string> m_queue;
        m_queue.push(start);
        unordered_set<string> m_visit;
        m_visit.insert(start);
        int m_length = 1;
        while (!m_queue.empty()) {
            m_length++;
            int cur_size = m_queue.size();
            for (int i = 0; i < cur_size; i++) { 
                string curr = m_queue.front();
                m_queue.pop();
                // m_visit.insert(curr); Can't set here,
                // because when we push new candidate, at that time make sure it's unique
                for (int j = 0; j < curr.length(); j++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == curr[j])
                            continue;
                        swap(c, curr[j]);
                        if (curr == end)
                            return m_length;
                        if (dict.find(curr) != dict.end() && m_visit.find(curr) == m_visit.end()) {
                            // set visited here
                            m_visit.insert(curr);
                            m_queue.push(curr);
                        }
                        swap(c, curr[j]); 
                    }
                }
            }
        }
        return 0;
    }
};
