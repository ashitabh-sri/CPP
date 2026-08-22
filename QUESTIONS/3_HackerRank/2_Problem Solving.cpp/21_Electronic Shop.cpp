// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b)
{

    int kmin = *min_element(keyboards.begin(), keyboards.end());
    int dmin = *min_element(drives.begin(), drives.end());
    if (kmin + dmin > b)
    {
        return -1;
    }

    int ksize = keyboards.size();
    int dsize = drives.size();
    int price = 0;
    for (int i = 0; i < ksize; i++)
    {
        for (int j = 0; j < dsize; j++)
        {
            int k1 = keyboards[i];
            int d1 = drives[j];
            int total = k1 + d1;

            if (total <= b && price < total)
            {
                price = total;
            }
        }
    }

    return price;
}