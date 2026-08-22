// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

int countingValleys(int steps, string path)
{
    int nvaly = 0;

    int level = 0;
    int valley = 0;
    for (int i = 0; i < steps; i++)
    {
        if (path[i] == 'U')
        {
            level++;
        }
        else if (path[i] == 'D')
        {
            level--;

            if (level < 0)
            {
                valley--;
            }
        }

        if (level == 0 && valley < 0)
        {
            nvaly++;
            valley = 0;
        }
    }

    return nvaly;
}