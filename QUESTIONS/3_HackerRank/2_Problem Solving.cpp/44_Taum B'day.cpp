// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

long taumBday(int b, int w, int bc, int wc, int z)
{
    long minc = 0;
    long B = b, W = w, BC = bc, WC = wc, Z = z;

    if (WC <= BC)
    {
        minc += W * WC;
        if (BC <= WC + Z)
            minc += B * BC;
        else
            minc += B * (WC + Z);
    }
    else
    {
        minc += B * BC;
        if (WC <= BC + Z)
            minc += W * WC;
        else
            minc += W * (BC + Z);
    }

    return minc;
}