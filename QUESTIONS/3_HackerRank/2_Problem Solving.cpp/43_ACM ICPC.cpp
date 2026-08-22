// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

vector<int> acmTeam(vector<string> topic)
{
    int n = topic.size();
    int m = topic[0].size();
    int mtop = 0;
    int mtms = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int ctop = 0;

            for (int k = 0; k < m; k++)
            {
                if (topic[i][k] == '1' || topic[j][k] == '1')
                    ctop++;
            }

            if (ctop > mtop)
            {
                mtop = ctop;
                mtms = 1;
            }
            else if (ctop == mtop)
                mtms++;
        }
    }

    return {mtop, mtms};
}