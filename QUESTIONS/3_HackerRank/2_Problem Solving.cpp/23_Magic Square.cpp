// https://www.hackerrank.com/challenges/magic-square-forming/problem?isFullScreen=true

int formingMagicSquare(vector<vector<int>> s)
{
    vector<int> cost;

    vector<int> range = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<vector<int>> mrows;
    int nrows = 0;
    for (int p = 0; p < 9; p++)
    {
        for (int q = 0; q < 9; q++)
        {
            for (int r = 0; r < 9; r++)
            {
                if (p != q && q != r && p != r)
                {
                    int sum = 0;
                    sum += range[p] + range[q] + range[r];
                    if (sum == 15)
                    {
                        mrows.push_back({range[p], range[q], range[r]});
                        nrows++;
                    }
                }
            }
        }
    }

    vector<vector<int>> magics;
    int ncols = 0;
    for (int p = 0; p < nrows; p++)
    {
        for (int q = 0; q < nrows; q++)
        {
            for (int r = 0; r < nrows; r++)
            {
                if (p != q && q != r && p != r)
                {
                    int pass = 0;
                    for (int s = 0; s < 3; s++)
                    {
                        int sum = 0;
                        sum += mrows[p][s] + mrows[q][s] + mrows[r][s];
                        if (sum == 15)
                        {
                            pass++;
                        }
                    }
                    int sum = 0;
                    sum += mrows[p][0] + mrows[q][1] + mrows[r][2];
                    if (sum == 15)
                    {
                        pass++;
                    }
                    sum = 0;
                    sum += mrows[p][2] + mrows[q][1] + mrows[r][0];
                    if (sum == 15)
                    {
                        pass++;
                    }
                    if (pass == 5)
                    {
                        vector<int> vals;
                        vals.insert(vals.end(), mrows[p].begin(), mrows[p].end());
                        vals.insert(vals.end(), mrows[q].begin(), mrows[q].end());
                        vals.insert(vals.end(), mrows[r].begin(), mrows[r].end());

                        sort(vals.begin(), vals.end());
                        bool perfect = true;
                        for (int q = 0; q < 9; q++)
                        {
                            if (vals[q] != q + 1)
                            {
                                perfect = false;
                                break;
                            }
                        }
                        if (!perfect)
                        {
                            continue;
                        }

                        magics.push_back(mrows[p]);
                        magics.push_back(mrows[q]);
                        magics.push_back(mrows[r]);
                        ncols += 3;
                    }
                }
            }
        }
    }

    for (int j = 0; j < (ncols - 2); j += 3)
    {
        int k = j + 1;
        int l = j + 2;
        int co1, co2, co3;
        co1 = co2 = co3 = 0;

        for (int m = 0; m < 3; m++)
        {
            co1 += abs(s[0][m] - magics[j][m]);
            co2 += abs(s[1][m] - magics[k][m]);
            co3 += abs(s[2][m] - magics[l][m]);
        }

        int cost1 = co1 + co2 + co3;
        cost.push_back(cost1);
    }

    int mincost = *min_element(cost.begin(), cost.end());

    return mincost;
}