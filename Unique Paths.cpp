#include <bits/stdc++.h> 

int uniquePaths(int m, int n) {

    int Nn=m+n-2;

    int R =m-1;

    double res=1;

    for(int i=1;i<=R;i++)

    {

        res=res* (Nn-R+i)/i;

    }

    return (int)res;

}