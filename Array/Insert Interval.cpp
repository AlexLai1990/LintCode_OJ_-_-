/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int size = intervals.size();
    	if (size == 0 || newInterval.end < newInterval.start) {
    		intervals.push_back(newInterval);
    		return intervals;
    	}
    	// find the first start > newInterval.start as left_bound
    	// find the first end < newInterval.end as right_bound
    	int left_bound = 0, right_bound = 0;
    	int start = 0, end = size - 1, mid = 0;
    	while (start <= end) {
    		mid = start + (end - start) / 2;
    		if (intervals[mid].start <= newInterval.start) {
    			start = mid + 1;
    		}
    		else {
    			end = mid - 1;
    		}
    	}
    	left_bound = start;
    	start = 0;
    	end = size - 1;
    	while (start <= end) {
    		mid = start + (end - start) / 2;
    		if (intervals[mid].end >= newInterval.end) {
    			end = mid - 1;
    		}
    		else {
    			start = mid + 1;
    		}
    	}
    	right_bound = end;
    	if (left_bound >= 1 && intervals[left_bound - 1].end >= newInterval.start) {
    		newInterval.start = min(intervals[--left_bound].start, newInterval.start);
    	}
    	if (right_bound < size - 1 && intervals[right_bound + 1].start <= newInterval.end)
    		newInterval.end = max(intervals[++right_bound].end, newInterval.end);
    
    	if (right_bound + 1 >= left_bound) {
    		intervals.insert(intervals.begin() + left_bound, newInterval);
    		intervals.erase(intervals.begin() + left_bound + 1, intervals.begin() + right_bound + 2);
    	} 
    	return intervals; 
    }
};