#include<stdio.h>

main()

{
 int n,i,j,avw=0;
 float avt=0,temp;
 int burst[10],wait[10],proc[10];

 printf("\n-------------------Process Scheduling(Shortest Job First Scheduling)----------------\n");

 printf("\nEnter the number of process : ");
 
scanf("%d",&n);
 
printf("Enter the Burst time\n");
//Taking burst values 
for(i=0;i<n;i++)

 {
   printf("Burst time P %d : ",i+1);
    scanf("%d",&burst[i]);
    proc[i] = i;
    printf("\n");
 }
//Swaping burst values in accordance to SJFS 
for(i=0;i<n;i++)

 {
    for(j=i;j<n;j++)
   {
   if(burst[i]>burst[j])
   {
   temp = burst[i];
burst[i]= burst[j];
burst[j]=temp;
temp = proc[i];
proc[i] = proc[j];
proc[j] = temp;
	}
   }
 }

 
 j=0;

for(i=0;i<n;i++)

 {
 wait[i] = j;
 j = burst[i] + j;
 }
 printf("\n");
 //printing gantt chart
 printf("----------------------------------GANTT CHART-------------------------------------------\n");
for(i=0;i<n;i++)

 {
printf("|\tP%d\t|",proc[i]+1);
 }
printf("\n");
printf("%d\t\t",0);
for(i=0;i<n;i++)

 {
printf("%d\t\t",wait[i]+burst[i]);
 }

 
 printf("\n\n");

 printf("\nProcess |  Burst time  |  Waiting time  | Turn around time \n");
 printf("\n____________________________________________________________\n"); 
 //printing Table and calvulating average wait time and turnaround time
 for(i=0;i<n;i++)

 {
printf("\nP%d\t|\t %d\t|\t%d\t|\t%d\t|",proc[i]+1,burst[i],wait[i],wait[i]+burst[i]);
printf("\n____________________________________________________________\n"); 
avw+=wait[i];
avt+=wait[i]+burst[i];
 }
 printf("\n\t\t\t\t%d\t\t%f\t",avw,(float)avt);
 printf("\n____________________________________________________________\n"); 
 printf("\n");

 printf("Average waiting time : %f\nAverage Turn around time : %f\n\n",avw/(float)n,avt/(float)n);
 }
