#include<bits/stdc++.h>
bool compareIntervals(const vector<int>& a, const vector<int>& b)
{
    return a[0] < b[0];
}

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end(), compareIntervals);

    vector<vector<int>> mergedIntervals;
    vector<int> currentInterval = intervals[0];

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= currentInterval[1]) {
            currentInterval[1] = max(currentInterval[1], intervals[i][1]);
        } else {
            mergedIntervals.push_back(currentInterval);
            currentInterval = intervals[i];
        }
    }

    mergedIntervals.push_back(currentInterval);

    return mergedIntervals;
}
