#include<bits/stdc++.h>
using namespace std;
void first_fit(int m, int b[])
{
    int i, j, n;
    int alloc[20], p[20], h[20], a[20];
    printf("Enter no. of divisions:\n");
    scanf("%d", &n);
    printf("Enter memory division:\n");
    for(i=0;i<n;++i)
    scanf("%d", &a[i]);
    for(i=0;i<n;++i)
    alloc[i]=0;
    for(i=0;i<n;++i)
    h[i]=0;
    for(i=0;i<m;++i)
    p[i]=0;
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
  if((b[i]<=a[j])&&(alloc[j]==0))
        {
            h[j]=a[j]-b[i];
            a[j]=b[i];
            p[j]=i+1;
            alloc[j]=0;
            break;
        }
        }
    }
    for(i=0;i<n;++i)
    {
        printf("P%d %d ", p[i], h[i]);
    }
    printf("\n");
}
void best_fit(int m, int b[])
{
    int i, j, n;
    int alloc[20], p[20], h[20], a[20];
    printf("Enter no. of divisions:\n");
    scanf("%d", &n);
    printf("Enter memory division:\n");
    for(i=0;i<n;++i)
    scanf("%d", &a[i]);
    for(i=0;i<n;++i)
    alloc[i]=0;
    for(i=0;i<n;++i)
    h[i]=0;
    for(i=0;i<m;++i)
    p[i]=0;
    for(i=0;i<n;++i)
        alloc[i]=0;
        sort(a, a+n);
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            if((b[i]<=a[j])&&(alloc[j]==0))
        {
            h[j]=a[j]-b[i];
            a[j]=b[i];
            p[j]=i+1;
            alloc[j]=1;
            break;
        }
        }
    }
    for(i=0;i<n;++i)
    {
        printf("P%d %d ", p[i], h[i]);
    }
    printf("\n");
}
void worst_fit(int m, int b[])
{
    int i, j, n;
    int alloc[20], p[20], h[20], a[20];
    printf("Enter no. of divisions:\n");
    scanf("%d", &n);
    printf("Enter memory division:\n");
    for(i=0;i<n;++i)
    scanf("%d", &a[i]);
    for(i=0;i<n;++i)
    alloc[i]=0;
    for(i=0;i<n;++i)
    h[i]=0;
    for(i=0;i<m;++i)
    p[i]=0;
    for(i=0;i<n;++i)
    alloc[i]=0;
    sort(a, a+n);
    for(i=0;i<m;++i)
    {
        for(j=n-1;j>0;--j)
        {
            if((b[i]<=a[j])&&(alloc[j]==0))
        {
            h[j]=a[j]-b[i];
            a[j]=b[i];
            p[j]=i+1;
            alloc[j]=1;
            break;
        }
        }
    }
    for(i=0;i<n;++i)
    {
        printf("P%d %d ", p[i], h[i]);
    }
    printf("\n");
}

main()
{
    int i, m, b[20];
    printf("Enter no. of processes:\n");
    scanf("%d", &m);
    printf("Enter the processes:\n");
    for(i=0;i<m;++i)
    scanf("%d", &b[i]);
    first_fit(m, b);
    best_fit(m, b);
    worst_fit(m, b);
}
