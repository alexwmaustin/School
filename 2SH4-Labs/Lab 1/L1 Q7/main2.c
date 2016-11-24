#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int i=1,n,x=1,sum=0;
    
    printf("Please input an integer: ");
    scanf("%d",&n);
    
    for(i;i<=n;i++)
    {
        for(x;x<i;x++)
        {
            if((i%x)==0)
            {
                sum += x;
            }
            if(sum == i&&x==(i-1))
            {
                printf("%d\n",i);
                sum = 0;
            }
            else if(sum > i)
                sum = 0;
        }
        sum=0;
        x=1;
    }
        
    return 0;
}

