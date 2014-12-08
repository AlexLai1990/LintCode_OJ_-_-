class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code here
        vector<vector<string> > m_ret;
        unordered_set<string> m_visit;
        // need to using unordered_set as queue
        // queue need to has traversal 
        unordered_set<string> m_queue, m_next_queue;
        m_queue.insert(start);
        bool stop = false;
        // using a hashtable to store all near parent and child
        unordered_map<string, vector<string> > m_prev;
        string find_end = "";
        while (!m_queue.empty() && !stop) {
            for (const auto &item : m_queue) {
                m_visit.insert(item);
            }
            for (const auto &curr : m_queue) {
                vector<string> m_curr_children = getAllValidString(curr, end, dict, m_visit);
                for (const auto &child : m_curr_children) {
                    if (child == end) {
                        stop = true;
                        find_end = end;
                    }
                    m_prev[child].push_back(curr);
                    m_next_queue.insert(child);
                }
            }
            m_queue.clear();
            swap(m_queue, m_next_queue);
        }
        if (find_end != "") {
            vector<string> temp_path;
            get_path(m_ret, temp_path, start, end, m_prev);
        }
        return m_ret;
    }
    
    // get the path from behind
    void get_path(vector<vector<string> > &m_ret, vector<string> &path, string start, string end, 
    unordered_map<string,vector<string> > &m_prev) {
        path.push_back(end);
        if (start == end) {
            // add one valid path
            vector<string> toAdd = path;
    		reverse(toAdd.begin(), toAdd.end());
    		m_ret.push_back(toAdd); 
        }
        else {
            for (const auto &word : m_prev[end]) {
    			get_path(m_ret, path, start, word, m_prev);
    		}
        } 
        path.pop_back();
        return;
    }
    
    vector<string> getAllValidString(string curr, string end, 
        unordered_set<string> &dict, unordered_set<string> &visit) {
        vector<string> m_res;
        for (int i = 0; i < curr.length(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == curr[i])
                    continue;
                swap (c, curr[i]);
                // if it existed before, it cannot be the shortest
                if ((dict.find(curr) != dict.end() || curr == end) && 
                    visit.find(curr) == visit.end())
                    m_res.push_back(curr);
                swap (c, curr[i]);
            }
        }
        return m_res;
    }
};
