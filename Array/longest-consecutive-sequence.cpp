int longestConsecutive(vector<int> &num) {
    // write you code here
    if (num.size() == 0 || num.size() == 1)
        return num.size();
    int m_ret_len = 1;
    unordered_map<int, bool> check;
    for (int i = 0; i < num.size(); i++) {
        check[num[i]] = false;
    }
    int temp_len = 0;
    int cur_value;
    for (int i = 0; i < num.size(); i++) {
        cur_value = num[i];
        if (check[cur_value] == true) 
            continue;
        else {
            temp_len = 1;
            check[cur_value] = true;
            int temp_value = cur_value;
            // find to left end
            while (check.find(--temp_value) != check.end()) {
                check[temp_value] = true;
                temp_len++;
            }
            temp_value = cur_value;
            while (check.find(++temp_value) != check.end()) {
                check[temp_value] = true;
                temp_len++;
            }
            if (temp_len > m_ret_len) {
                m_ret_len = temp_len;
            }
        }
    }
    return m_ret_len;
}