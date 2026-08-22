// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

string catAndMouse(int x, int y, int z)
{
    string wins;

    int distA = abs(x - z);
    int distB = abs(y - z);

    (distA < distB) ? wins = "Cat A" : wins = "Cat B";

    if (distA == distB)
    {
        wins = "Mouse C";
    }

    return wins;
}