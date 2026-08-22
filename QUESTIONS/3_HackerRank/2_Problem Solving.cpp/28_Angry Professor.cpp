// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

string angryProfessor(int k, vector<int> a)
{
    int stime = 0, size = a.size();

    for (int i = 0; i < size; i++)
    {
        int time = a[i];
        if (time <= 0)
        {
            stime++;
        }
    }

    return (k <= stime ? "NO" : "YES");
}