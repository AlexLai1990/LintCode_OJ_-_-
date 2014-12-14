class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){  
        // balanced binary tree to store value, index 
        map<int, int> bst;
    	bst[0] = -1;
    	// boundaries
    	bst[INT_MIN] = -2;
    	bst[INT_MAX] = nums.size();
        
    	vector<vector<int> > m_res;
        int closestNumber = 0; 
        int gap = INT_MAX; 
        
    	int sum = 0;
    	for (int i = 0; i < nums.size(); ++i) {
    		sum += nums[i];
    		// O(lgN) to find the fisrt >= sum - closestNumber
    		map<int, int>::iterator it = bst.lower_bound(sum - closestNumber);
    		int tmp_gap = abs(closestNumber - (sum - it->first)); 
    		if (tmp_gap == gap) { 
    		    // add one more possible result
    			vector<int> temp(2, -1);
    			temp[0] = it->second + 1;
    			temp[1] = i;
    			m_res.push_back(temp);
    		}
    		if (tmp_gap < gap && it->first != INT_MIN && it->first != INT_MAX) {
    			gap = tmp_gap;  
    			// update result need to clear the previous result
    			m_res.clear();
    			vector<int> temp(2,-1);
    			temp[0] = it->second + 1;
    			temp[1] = i;
    			m_res.push_back(temp);
    		}
    
    		--it;
    		// O(lgN) to find the last value < sum - closestNumber
    		tmp_gap = abs(closestNumber - (sum - it->first));
    		if (tmp_gap == gap) { 
    			vector<int> temp(2, -1);
    			temp[0] = it->second + 1;
    			temp[1] = i;
    			m_res.push_back(temp);
    		}
    		if (tmp_gap < gap && it->first != INT_MIN && it->first != INT_MAX) {
    			gap = tmp_gap; 
    			// update result need to clear the previous result 
    			m_res.clear();
    			vector<int> temp(2, -1);
    			temp[0] = it->second + 1;
    			temp[1] = i;
    			m_res.push_back(temp);
    		} 
    		bst[sum] = i;
    	}
    	
    	if (m_res.size() == 0)
    	    m_res.push_back(vector<int> (2,0));
    	
    	// we just need to return one possible combination.
    	return m_res[0];
    }
};

