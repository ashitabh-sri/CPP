// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

string dayOfProgrammer(int year)
{
    string date = "00.00.0000";

    string y = to_string(year);
    for (int i = 6; i <= 9; i++)
    {
        date[i] = y[i - 6];
    }

    if (year == 1918)
    {
        date[0] = '2';
        date[1] = '6';
        date[4] = '9';
    }

    else if (year < 1918)
    {
        date[0] = '1';
        date[4] = '9';

        if (year % 4 == 0)
        {
            date[1] = '2';
        }

        else
        {
            date[1] = '3';
        }
    }

    else if (year > 1918)
    {
        date[0] = '1';
        date[4] = '9';

        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            date[1] = '2';
        }

        else
        {
            date[1] = '3';
        }
    }

    return date;
}