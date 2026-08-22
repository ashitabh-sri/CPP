// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

int squares(int a, int b) {
    int nsq = 0;
    
    int lroot = ceil(sqrt(a));
    int uroot = floor(sqrt(b));    
    if(uroot >= lroot) nsq = uroot - lroot + 1;
    
    return nsq;
}