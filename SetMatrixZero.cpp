#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int rows = matrix.size();
    int columns = matrix[0].size();
    vector<int> row(rows, 0);
    vector<int> cols(columns, 0);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = -1;
                cols[j] = -1;
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (row[i] == -1 || cols[j] == -1)
                matrix[i][j] = 0;
        }
    }
	

}