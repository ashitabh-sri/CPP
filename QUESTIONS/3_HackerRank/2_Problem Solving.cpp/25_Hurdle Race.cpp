// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

int hurdleRace(int k, vector<int> height)
{
    int mindose = 0;

    sort(height.rbegin(), height.rend());
    int maxheight = height[0];

    if (maxheight > k)
    {
        mindose = maxheight - k;
    }

    return mindose;
}