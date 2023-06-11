#include<bits/stdc++.h>

long countWaysToMakeChange(int *denominations, int n, int value)
{
    long table[value + 1];
    memset(table, 0, sizeof(table)); 

    table[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = denominations[i]; j <= value; j++)
        {
            table[j] += table[j - denominations[i]];
        }
    }

    return table[value];
}