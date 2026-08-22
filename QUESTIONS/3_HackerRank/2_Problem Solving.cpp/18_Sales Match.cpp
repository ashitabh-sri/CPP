// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

int sockMerchant(int n, vector<int> ar)
{
    map<int, int> freq;
    for (int sc : ar)
    {
        freq[sc]++;
    }

    int npairs = 0;
    for (auto f : freq)
    {
        npairs += f.second / 2;
    }

    return npairs;
}