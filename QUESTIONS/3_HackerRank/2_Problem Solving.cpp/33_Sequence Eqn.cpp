// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

vector<int> permutationEquation(vector<int> p)
{
    vector<int> yval;

    vector<int> xval = p;
    sort(xval.begin(), xval.end());
    for (int x : xval)
    {
        auto index = distance(p.begin(), find(p.begin(), p.end(), x));
        index++;
        auto index1 = distance(p.begin(), find(p.begin(), p.end(), index));
        index1++;
        yval.push_back(index1);
    }

    return yval;
}