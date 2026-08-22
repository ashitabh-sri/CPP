// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

vector<int> gradingStudents(vector<int> grades)
{
    vector<int> fgrad;
    fgrad = grades;

    for (int a = 0; a < fgrad.size(); a++)
    {
        int b = fgrad[a];

        if (b >= 38)
        {
            int c;
            c = ((b + 5) / 5) * 5; // Next multiple of 5
            int d;
            d = c - b; // Difference of grade with c

            if (d < 3)
            {
                b = c;
            }
        }
        fgrad[a] = b;
    }

    return fgrad;
}