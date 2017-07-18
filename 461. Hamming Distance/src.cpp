#include <stdio.h>

int hammingDistance(int x, int y) {
    int c = x ^ y; 
    int cnt = 0;
    while(c){
        cnt += c & 1;
        c = c >> 1;
    }; 
    return cnt;
}
    
void main()
{
    int a = 1, b = 4;
    printf("%d", hammingDistance(1, 4));
}
