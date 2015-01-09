class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end)
            return 0; 
    	queue<string> q_front, q_back;
    	q_front.push(start);
    	q_back.push(end);
	    unordered_map<string, int> s_front({ { start, 1 } });
	    unordered_map<string, int> s_back({ { end, 1 } });
        while (!q_front.empty() || !q_back.empty()) {
            if ((q_front.empty() || q_front.size() < q_back.size()) && !q_back.empty()) {
                swap(q_front, q_back);
                swap(s_front, s_back);
            }
            string curr = q_front.front();
            q_front.pop();
            int curr_step = s_front[curr];
            for (int i = 0; i < curr.length(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (curr[i] == c)
                        continue;
                    swap(c, curr[i]);
                    if (s_back.find(curr) != s_back.end())
                        return curr_step + s_back[curr];
                    if (dict.find(curr) != dict.end() && s_front.find(curr) == s_front.end()) {
                        s_front[curr] = curr_step + 1;
                        q_front.push(curr);
                    }
                    swap(c, curr[i]);
                }
            } 
        } 
        return 0;
    }
};
