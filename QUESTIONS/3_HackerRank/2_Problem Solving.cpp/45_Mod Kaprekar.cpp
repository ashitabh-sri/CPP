// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

void kaprekarNumbers(int p, int q)
{
    bool chk = false;

    for (long long i = p; i <= q; i++)
    {
        if (i == 1)
        {
            chk = true;
            cout << i << " ";
            continue;
        }

        string S = to_string(i * i);
        long long n = S.size();
        string l = S.substr(0, (n / 2));
        string r = S.substr(n / 2);
        if (l.empty())
            l = '0';
        long long sum = stoi(l) + stoi(r);
        if (sum == i)
        {
            chk = true;
            cout << i << " ";
        }
    }

    if (!chk)
        cout << "INVALID RANGE";
}