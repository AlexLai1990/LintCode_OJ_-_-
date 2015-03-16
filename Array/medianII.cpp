class compareInt{
public:
	bool operator()(int a, int b) {
		if (a > b)
			return true;
		else
			return false;
	}
};

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        vector<int> m_res = nums;
        if (nums.size() == 1)
            return m_res;
        priority_queue<int, vector<int>, std::less<int>> m_max;
        priority_queue<int, vector<int>, compareInt> m_min;
        m_max.push(min(nums[0], nums[1]));
        m_min.push(max(nums[0], nums[1])); 
        m_res[1] = nums[1] > nums[0] ? nums[0] : nums[1];
        int curr_median = nums[0];
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] >= m_min.top()) 
                m_min.push(nums[i]);
            else if (nums[i] <= m_max.top())
                m_max.push(nums[i]);
            else 
                m_min.push(nums[i]);
            // checking heaps makes the difference of their sizes is not larger than 1
            if (int(m_min.size() - m_max.size()) > 1){
				curr_median = m_min.top();
				m_min.pop();
				m_max.push(curr_median);
			}
			if (int(m_max.size() - m_min.size()) > 1) {
				curr_median = m_max.top();
				m_max.pop();
				m_min.push(curr_median);
			}
            // update result
            m_res[i] = m_min.size() <= m_max.size() ? m_max.top():m_min.top();
        }
        return m_res;
    }
};

// Solution 2. CC version
// When do the insertion, keep the left half size (stored in max_heap) larger or equal to right size.
// base on this situation, the median is just on the top of max_heap.

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        vector<int> m_res = nums;
        if (nums.size() == 1)
            return m_res;
        priority_queue<int, vector<int>, std::less<int> > m_max;
        priority_queue<int, vector<int>, std::greater<int> > m_min;
         
        int curr_median = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            // based on the difference size of max heap and min heap
            if (m_max.size() == m_min.size()) {
                if (m_min.size() != 0 && m_min.top() < nums[i]) {
                    m_max.push(m_min.top());
                    m_min.pop();
                    m_min.push(nums[i]);
                }
                else  
                    m_max.push(nums[i]);
            }
            else {
                // m_max size is larger than m_min
                if (m_max.top() > nums[i]) {
                    m_min.push(m_max.top());
                    m_max.pop();
                    m_max.push(nums[i]);
                }
                else 
                    m_min.push(nums[i]);
            }  
            m_res[i] = m_max.top();
        }
        return m_res;
    }
};


