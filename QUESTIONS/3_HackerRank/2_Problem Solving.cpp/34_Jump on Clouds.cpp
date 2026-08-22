// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

int jumpingOnClouds(vector<int> c, int k)
{
    int energy = 100;

    int n = c.size();
    for (int i = 0; i < 28; i += k)
    {
        energy--;
        if (c[(i + k) % n] == 1)
        {
            energy -= 2;
        }
        if ((i + k) % n == 0)
        {
            break;
        }
    }

    return energy;
}