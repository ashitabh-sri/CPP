// www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

vector<int> breakingRecords(vector<int> scores)
{

    vector<int> broke;
    int a = 0;
    int b = 0;

    int hscore, lscore;
    hscore = lscore = scores.at(0);

    for (int i = 1; i < scores.size(); i++)
    {
        int hs = scores.at(i);
        int ls = scores.at(i);

        if (hscore < hs)
        {
            hscore = hs;
            a++;
        }

        else if (lscore > ls)
        {
            lscore = ls;
            b++;
        }
    }

    broke.push_back(a);
    broke.push_back(b);

    return broke;
}