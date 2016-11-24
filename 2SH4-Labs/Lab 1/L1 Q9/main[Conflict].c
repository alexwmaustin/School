#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int n,counter1,counter0,count,h,chng=1,z,x;
    
    FILE *input_file=fopen("data.txt","r");
    FILE *input_file2=fopen("data2.txt","r");
    FILE *output_file=fopen("output.txt", "w");
    FILE *output_file2=fopen("output2.txt", "w");
    
    
    fscanf(input_file,"%d",&n);
    
    while(fscanf(input_file,"%d",&n) != EOF)
    {
        if(n == 1)
        {
            counter1++;
            if(counter1 <= 1)
            {
                fprintf(output_file,"%d ", counter0 );
            }
            counter0=0;
        }
        
        if(n == 0)
        {
            counter0++;
            if(counter0 <= 1)
            {
               fprintf(output_file,"%d ",counter1 );
            }
            counter1=0;
        }
        
    }
    if(counter0 > 0)
    {
        fprintf(output_file,"%d ",counter0 );
        count++;
    }
    else
    {
        fprintf(output_file,"%d ",counter1 );
        count++;
    }
    
    fscanf(input_file2,"%d",&h);
    
    while(fscanf(input_file2,"%d",&h) != EOF)
    {
        if(chng == 1)
        {
            for(x;x < h;x++)
                fprintf(output_file2,"0");
            chng=0;
            x=0;
        }
        else if(chng == 0)
        {
            for(z;z < h;z++)
                fprintf(output_file2,"1");
            chng=1;
            z=0;
        }
    }
    fclose(input_file);
    fclose(input_file2);
    fclose(output_file);
    fclose(output_file2);

    return 0;
}

