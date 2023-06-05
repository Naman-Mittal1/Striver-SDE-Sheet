#include <bits/stdc++.h>


bool compare(const vector<int> &a, const vector<int> &b)
{
    return a[1] > b[1]; 
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    int maxDeadline = 0;

    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }

    sort(jobs.begin(), jobs.end(), compare);

    vector<bool> slots(maxDeadline + 1, false);
    int maxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        int deadline = jobs[i][0];
        int profit = jobs[i][1];

        for (int j = deadline; j >= 1; j--)
        {
            if (!slots[j])
            {
                slots[j] = true; 
                maxProfit += profit; 
                break;
            }
        }
    }

    return maxProfit;
}