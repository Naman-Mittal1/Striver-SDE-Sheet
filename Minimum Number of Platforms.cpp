int calculateMinPatforms(int at[], int dt[], int n) {
    int minTime = *min_element(at, at + n);
    int maxTime = *max_element(dt, dt + n);

    vector<int> trainCount(maxTime - minTime + 2, 0);

    for (int i = 0; i < n; i++) {
        trainCount[at[i] - minTime]++;
        trainCount[dt[i] - minTime + 1]--;
    }

    int platforms = trainCount[0];
    int maxPlatforms = platforms;
    for (int i = 1; i < trainCount.size(); i++) {
        platforms += trainCount[i];
        maxPlatforms = max(maxPlatforms, platforms);
    }

    return maxPlatforms;
}


// Less Optimized approach

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);

    int platformCount = 0;
    int maxPlatforms = 0;
    int i = 0, j = 0;

    while (i < n && j < n) {
        if (at[i] <= dt[j]) {
            platformCount++;
            i++;
        } else {
            platformCount--;
            j++;
        }

        if (platformCount > maxPlatforms) {
            maxPlatforms = platformCount;
        }
    }

    return maxPlatforms;
}