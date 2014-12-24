#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
    	unordered_map<int, int> m_dict;
    	// int m_majority;
    	for (int i = 0; i < nums.size(); i++) {
    		if (m_dict.find(nums[i]) != m_dict.end()) {
    			m_dict[nums[i]]++;
    		}
    		// what if nums[i] is not in m_dict
    		else if (m_dict.size() == 2) {
    			vector<unordered_map<int, int>::iterator> m_del;
    			for (auto it = m_dict.begin(); it != m_dict.end(); it++) {
    				if (--(it->second) == 0)
    					m_del.push_back(it);
    			}
    			for (auto item : m_del) {
    				m_dict.erase(item);
    			}
    		}
    		else {
    			m_dict[nums[i]] = 1;
    		}
    	}
    	if (m_dict.size() == 0)
		    return m_dict.begin()->first;
    	else {
    		int m_majority, count = INT_MIN;
    		for (auto it = m_dict.begin(); it != m_dict.end(); it++) { 
    			int temp_count = 0;
    			for (int i = 0; i < nums.size(); i++) {
    				if (nums[i] == it->first)
    					temp_count++;
    				if (count < temp_count) {
    					count = temp_count;
    					m_majority = it->first; 
    				}
    			}
		    }
		    return m_majority;
	    }
    }
};

