#include <stdio.h>
void filled_arr(int n,int m,double source[n][m]);
void copy_arr(int n,int m,double source [n][m],double target[n][m]);
void print_ptr(int n,int m,double (*p)[m]);
int main(void)
{
    int n,m;
    double source[n][m];
    double target[n][m];

    printf("Please enter the NxM array:\n");
    scanf("%d %d",&n,&m);

    printf("Please enter the number into the array:\n");
    filled_arr(n,m,source);

    copy_arr(n,m,source,target);
    print_ptr(n,m,source);
    print_ptr(n,m,target);

    return 0;
}

void filled_arr(int n,int m,double source[n][m])
{
    int r,c;

    for(r=0;r<n;r++)
        for(c=0;c<m;c++)
        scanf("%lf",&source[r][c]);
}

void copy_arr(int n,int m,double source[n][m],double target [n][m])
{
    int r,c;

    for(r=0;r<n;r++)
        for(c=0;c<m;c++)
        target[r][c]=source[r][c];
}

void print_ptr(int n,int m,double (*p)[m])
{
    int r,c;

    for(r=0;r<n;r++)
        for(c=0;c<m;c++)
        printf("%lf ",*(*(p+r)+c));
    putchar('\n');
}
