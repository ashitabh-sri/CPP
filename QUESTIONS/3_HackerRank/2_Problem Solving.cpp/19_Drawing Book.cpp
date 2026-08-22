// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

int pageCount(int n, int p)
{
    int minpage = 0;
    int m1, m2;
    m1 = m2 = 0;

    for (int i = 1; i <= n; i += 2)
    {
        if (i < p)
        {

            if (i + 1 == p)
            {
                m1++;
                break;
            }

            m1++;
        }

        else if (i >= p)
        {
            break;
        }
    }

    for (int j = n; j >= 1; j -= 2)
    {
        if (j > p)
        {

            if (j - 1 == p)
            {
                if (j % 2 != 0)
                {
                    break;
                }

                else if (j % 2 == 0)
                {
                    m2++;
                    break;
                }
            }

            m2++;
        }

        else if (j <= p)
        {
            break;
        }
    }

    minpage = (m1 < m2) ? m1 : m2;

    return minpage;
}