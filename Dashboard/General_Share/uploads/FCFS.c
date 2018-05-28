#include<stdio.h>
struct process
{
        int id;
        int time;
        int AT;
};
void main()
{
        int n,i,TAT,WT,RT,TOT,PT;
        printf("Enter number of processes:");
        scanf("%d",&n);
        struct process p[n+1];
        for(i = 0 ;i < n ; i++)
        {
               printf("Process id: p%d\nEnter time:",i+1);
               p[i].id = i;
               p[i].AT = 0;
               scanf("%d",&p[i].time);
               printf("Enter Arrival Time:");
               scanf("%d",&p[i].AT);
        }
        printf("\n\nProcess\tTime\tArrival Time\n");
         for(i = 0 ;i < n ; i++)
         {
                printf("p%d\t%d\t%d\n",p[i].id+1,p[i].time,p[i].AT);
         }
         printf("\n\nOrder of executing the process is:\n");
         //Process p1 starts here
          TOT = p[0].time;
          PT = 0;
           for(i = 0 ;i < n ; i++)
           {
                TAT = TOT - p[i].AT;
                WT = TAT - p[i].time;
                RT = PT - p[i].AT;
                // TOT time of clock increased for next process.
                PT = TOT;
                TOT = TOT + p[i+1].time;
                //Output
                printf("For p%d\nTurn Around time = %d\nWaiting Time = %d\nResponse Time = %d\n\n",i+1,TAT,WT,RT);
           }
}
