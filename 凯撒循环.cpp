#include<stdio.h>
int *solve(int *s,int n,int m){
    /*********Begin*********/
    int i;
    int *a;
    for(i=0;i<n;i++)
    {
        a[i]=s[(i+m)%n];
    }
    return a;
    /*********End**********/
}
int main()
{
    int n,m,s[110];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    int *ans;
    /*********Begin*********/
    ans = solve(s,n,m);
    /*********End**********/
    for(int i=0;i<n;i++){
        if(i==0)    
            printf("%d",*ans++ );
        else    
            printf(" %d",*ans++ );
    }
    return 0;
}
