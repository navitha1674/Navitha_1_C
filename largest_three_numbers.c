#include<stdio.h>
int largest(int a, int b, int c) {
    if(a>=b && a>=c) return a;
    if(b>=a && b>=c) return b;
    return c;
}
int main () {
    int x, y, z;
    printf ("Enter three number. ") ;
    scanf ("%d%d%d", &x,&y,&z) ;
    printf ("Largest=%d\n",largest (x, y, z)) ;
    return 0;
}
