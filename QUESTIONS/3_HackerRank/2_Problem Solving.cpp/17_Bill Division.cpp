// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

void bonAppetit(vector<int> bill, int k, int b)
{
    int actual = 0;

    for (int i = 0; i < bill.size(); i++)
    {
        if (i == k)
        {
            continue;
        }

        actual += bill.at(i);
    }
    actual /= 2;

    if (actual != b)
    {
        cout << b - actual;
    }

    else if (actual == b)
    {
        cout << "Bon Appetit";
    }
}