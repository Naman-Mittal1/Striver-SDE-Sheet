bool searchMatrix(vector<vector<int>>& mat, int target) {

    int ans = false;

    int m = mat.size();
    int n = mat[0].size();

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mat[i][j] == target)
            {
                return true;
                break;
            }
        }
    }

    return false;
}