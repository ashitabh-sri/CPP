// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

void plusMinus(vector<int> arr)
{

    int a, b, c;
    a = b = c = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            a++;
        }
        else if (arr[i] < 0)
        {
            b++;
        }
        else
        {
            c++;
        }
    }

    cout << (double)a / n << "\n";
    cout << (double)b / n << "\n";
    cout << (double)c / n << "\n";
}