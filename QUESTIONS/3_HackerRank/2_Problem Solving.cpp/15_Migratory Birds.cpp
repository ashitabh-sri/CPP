// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

int migratoryBirds(vector<int> arr)
{
    int htype = 0;

    int t1, t2, t3, t4, t5;
    t1 = t2 = t3 = t4 = t5 = 0;

    for (long unsigned int i = 0; i < arr.size(); i++)
    {
        int type = arr.at(i);

        switch (type)
        {

        case 1:
            t1++;
            break;

        case 2:
            t2++;
            break;

        case 3:
            t3++;
            break;

        case 4:
            t4++;
            break;

        case 5:
            t5++;
            break;
        }
    }

    int maxf1 = (t1 > t2) ? ((t3 > t1) ? t3 : t1) : ((t3 > t2) ? t3 : t2);
    int maxf = (maxf1 > t4) ? ((maxf1 > t5) ? maxf1 : t5) : ((t4 > t5) ? t4 : t5);

    if (maxf == t1)
    {
        htype = 1;
    }

    else if (maxf == t2)
    {
        htype = 2;
    }

    else if (maxf == t3)
    {
        htype = 3;
    }

    else if (maxf == t4)
    {
        htype = 4;
    }

    else if (maxf == t5)
    {
        htype = 5;
    }

    return htype;
}