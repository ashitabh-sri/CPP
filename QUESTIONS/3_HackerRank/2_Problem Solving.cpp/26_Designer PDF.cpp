// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

int designerPdfViewer(vector<int> h, string word)
{
    int rarea;
    int maxh = 0, lnum = word.length();

    for (int i = 0; i < word.length(); i++)
    {
        char letter = word[i];
        int ascii = letter;
        int index = ascii - 97;
        int height = h[index];
        maxh = max(maxh, height);
    }
    rarea = maxh * lnum;

    return rarea;
}