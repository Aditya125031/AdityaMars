#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WINDOWSIZE 3
void muchiko(float *data, float *filtereddata, int size)//muchiko filter takes average of 3 values at a time and stores it in a filtered array having 2 elements less than the original data
{
    for(int i=0;i<size-2;i++)
    {
        float window[3];
        for(int j=0;j<3;j++)//making a separate window for groups of 3 elements
        {
            window[j]=data[i+j];
        }
        float sum=0;
        for(int j=0;j<3;j++)//summing an dfinding the average of groups of 3
        {
            sum+=window[j];
        }
        sum=sum/3;
        filtereddata[i]=sum;
    }
}
void sanchiko(float *data,float *filtereddata,int size)//sanchiko filter makes groups of 3 and sorts them to find the median or the middle value in this case
{
    float window[3];
    for (int i=0;i<size-2;i++) 
    {
        for(int j=0;j<3;j++)making a separate window for groups of 3 elements
        {
            window[j]=data[i+j];
        }
        for(int j=0;j<3;j++) // sorting the elements 
        {
            for(int k=0;k<3-j-1;k++) 
            {
                if(window[k]>window[k+1]) 
                {
                    float temp=window[k];
                    window[k]=window[k+1];
                    window[k+1]=temp;
                }
            }
        }
        filtereddata[i]=window[1];//taking the middle value in this case
    }
}
void hybrid(float *data, float *filtereddata, int size)//hybrid of sanchikko and muchiko filters,i tried muchiko sanchiko but this gives better results so i sticked with this
{
    float* sanchikodata=(float*)malloc(size*sizeof(float));
    sanchiko(data,sanchikodata,size);
    muchiko(sanchikodata,filtereddata,size);
    free (sanchikodata);
}
float variance(float *data, int size)//fucntion to calculate the variance of the data
{
    float mean=0;
    for(int i=0;i<size;i++)
    {
        mean+=data[i];
    }
    mean/=(size);
    float variance=0;
    for(int i=0;i<size;i++)
    {
        variance+=(data[i]-mean)*(data[i]-mean);
    }
    variance/=(size);
    return variance;
}
int main()
{
    int size;
    scanf("%d",&size);
    float noisevalue[size];
    for(int i=0;i<size;i++)//taking the noise inputs
    {
        scanf("%f",&noisevalue[i]);
    }
    //allocating memory to the filters
    float *muchikoresult = (float *)malloc(size * sizeof(float));
    float *sanchikoresult = (float *)malloc(size * sizeof(float));
    float *hybridresult = (float *)malloc(size * sizeof(float));
    //calling alll the filter fucntions
    muchiko(noisevalue,muchikoresult,size);
    sanchiko(noisevalue,sanchikoresult,size);
    hybrid(noisevalue,hybridresult,size);
    printf("\nnoisedata");
    //output for reference
    for(int i=0;i<size;i++)
    {
        printf("%.3f ",noisevalue[i]);
    }
    printf("\nmuchiko data");
    for(int i=0;i<size-2;i++)
    {
        printf("%.3f ",muchikoresult[i]);
    }
    printf("\nsanchiko data");
    for(int i=0;i<size-2;i++)
    {
        printf("%.3f ",sanchikoresult[i]);
    }
    printf("\nhybrid data");
    for(int i=0;i<size-4;i++)
    {
        printf("%.2f ",hybridresult[i]);
    }
    //calculating variance of each result
    float muchikovariance=variance(muchikoresult,size-2);
    float sanchikovariance=variance(sanchikoresult,size-2);
    float hybridvariance=variance(hybridresult,size-4);
    printf("\nmuchiko variance: %f\n",muchikovariance);
    printf("sanchiko variance: %f\n",sanchikovariance);
    printf("hybrid variance: %f\n",hybridvariance);
    //finding the lowest variance and cocnluding the best filter for the situation
    if(hybridvariance<sanchikovariance && hybridvariance<muchikovariance)
    {
        printf("Hybrid filter is the best");
    }
    else if(sanchikovariance<muchikovariance)
        printf("Sanchiko filter is the best");
    else
        printf("Muchiko filter is the best");
    free(muchikoresult);
    free(sanchikoresult);
    free(hybridresult);
    return 0;
}
