// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

int viralAdvertising(int n)
{
    int clike = 0, ppl = 5;

    for (int i = 1; i <= n; i++)
    {
        int like = ppl / 2;
        clike += like;
        ppl = like * 3;
    }

    return clike;
}