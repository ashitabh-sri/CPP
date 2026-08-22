// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

int pickingNumbers(vector<int> a)
{
    int maxfr = 0;

    map<int, int> mfreq;
    for (int num : a)
    {
        mfreq[num]++;
    }

    for (auto const &[key, value] : mfreq)
    {
        auto it = mfreq.find(key + 1);
        int neighbour = (it == mfreq.end() ? 0 : it->second);
        maxfr = max(maxfr, value + neighbour);
    }

    return maxfr;
}