// reference: http://www.meetqun.com/forum.php?mod=viewthread&tid=3742&ctid=8

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        for (int i = 0; i < colors.size(); i++) {
            // not visted before
            if (colors[i] > 0) {
                int curr_index = colors[i];
                // first visited
                colors[i] = 0;
                while (true) {
                    // if prev have been visited
                    if (colors[curr_index - 1] <= 0) {
                        colors[curr_index - 1]--;
                        break;
                    }
                    int next_visit = colors[curr_index - 1];
                    colors[curr_index - 1] = -1; // visited once
                    curr_index = next_visit;
                }
            }
        }
        int start = colors.size() - 1;
        for (int i = start; i >= 0; i--) {
            for (int j = 0; j < abs(colors[i]); j++) {
                colors[start--] = i + 1;
            }
        }
        return ;
    }
};
