#include<stdio.h>
struct process
{
        int id;
        int bt;
        int at;
};
struct Sortprocess
{
        int id;
        int bt;
        int at;
};
void main()
{
        int n,i,min,j,temp1,temp2,temp3,TOT,PT,TAT,RT,WT;
        printf("Enter number of processes:");
        scanf("%d",&n);
        struct process p[n];
        struct Sortprocess q[n];
        for( i = 0 ; i < n ; i++ )
        {
                printf("Enter Process %d->\nBurst Time:",i+1);
                scanf("%d",&p[i].bt);
                p[i].id = i;
                p[i].at = 0;
                printf("\nEnter Arrival Time:%d",p[i].at);
                //scanf("%d",&p[i].at);
        }
        printf("\n----------------------------------------------\nprocess\tBurst Time\tArrival Time\n");
        for( i = 0 ; i < n ; i++ )
        {
               printf("p%d\t%d\t\t%d\n",p[i].id,p[i].bt,p[i].at);
        }
        //Find minimun Burst time in processes and arrange in ascnding order:
        for(i=0;i<n;i++)
        {
             for(j=0;j<n;j++)
             {
                if(p[j].bt > p[i].bt)
                {
                        temp1 = p[i].id;
                        temp2 = p[i].bt;
                        temp3 = p[i].at;
                        p[i].id = p[j].id;
                        p[i].bt = p[j].bt;
                        p[i].at = p[j].at;
                        p[j].id = temp1;
                        p[j].bt = temp2;
                        p[j].at = temp3;
                }
             }   
        }
        //Swapping done
        printf("After Arranging:\n");
        printf("\n----------------------------------------------\nprocess\tBurst Time\tArrival Time\n");
        for( i = 0 ; i < n ; i++ )
        {
               printf("p%d\t%d\t\t%d\n",p[i].id,p[i].bt,p[i].at);
        }
        TOT = p[0].bt;
        PT = 0;
          for(i = 0 ;i < n ; i++)
          {
               TAT = TOT - p[i].at;
               WT = TAT - p[i].bt;
               RT = PT - p[i].at;
               // TOT time of clock increased for next process.
               PT = TOT;
               TOT = TOT + p[i+1].bt;
               //Output
               printf("For p%d\nTurn Around time = %d\nWaiting Time = %d\nResponse Time = %d\n\n",i+1,TAT,WT,RT);
           }
        
        printf("\n-------------------------------------------------\n");
}
