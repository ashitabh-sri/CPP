// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

int birthdayCakeCandles(vector<int> candles)
{

    int i = 0;
    int talc = candles[0];
    for (i = 1; i < candles.size(); i++)
    {
        if (talc < candles[i])
        {
            talc = candles[i];
        }
    }

    int noc = 0;
    for (int j = 0; j < candles.size(); j++)
    {
        if (candles[j] == talc)
        {
            noc += 1;
        }
    }

    return noc;
}