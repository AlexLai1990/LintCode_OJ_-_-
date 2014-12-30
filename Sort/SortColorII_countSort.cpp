class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        vector<int> counts(k + 1, 0);
        for (int i = 0; i < colors.size(); i++) {
            counts[colors[i]]++;
        }
        int curr = 0;
        for (int i = 1; i < counts.size(); i++) {
            for (int j = 0; j < counts[i]; j++)
                colors[curr++] = i;
        }
        
        return;
    }
};
