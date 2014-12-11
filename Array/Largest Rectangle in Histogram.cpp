class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        if (height.size() < 1)
            return 0;
        // put one -1 in the height to make sure calculation
        height.push_back(-1);
        // store the indexes of a increasing sequence
        stack<int> m_stack;
        int m_max_area = 0;
        int i = 0;
        while (i < height.size()) {
            if (m_stack.empty() || height[i] >= height[m_stack.top()]) {
                m_stack.push(i++); 
            }
            else {
                int prev_index = m_stack.top();
                m_stack.pop();
                int m_height = height[prev_index];
                // if m_stack.empty(), means prev_height is the lowest for current index.
                // because the stack is keeping increasing.
                int m_width = m_stack.empty() ? i : i - m_stack.top() - 1;
                int m_area = m_height * m_width;
                if (m_area > m_max_area)
                    m_max_area = m_area;
            }
        }
        return m_max_area;
    }
};

