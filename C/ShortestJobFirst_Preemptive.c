/*

	Author : Sayantan Banerjee (2018IMT-093)
	
	Shortest Scheduling Algorithm
	Preemptive
*/
#include "stdio.h"
#include "stdlib.h"
struct process
{
	int process_id;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turn_around_time;
	int remain_time;
};
int main()
{
	int n,i,j;
	int bt=0,k=1,tat=0,sum=0,min;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	struct process proc[n],temp;
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("Enter arrival time for process %d : ",i+1);
		scanf("%d",&proc[i].arrival_time);
		printf("Enter burst time for process %d : ",i+1);
		scanf("%d",&proc[i].burst_time);
		proc[i].remain_time = proc[i].burst_time;
		proc[i].process_id = i+1;
	}
	int quantum_time,flag=0;
	printf("Enter time quantum: ");
	scanf("%d",&quantum_time);
	int processes_remaining=n;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(proc[i].arrival_time < proc[j].arrival_time)
			{
				temp = proc[j];
				proc[j] = proc[i];
				proc[i] = temp;
			}
		}
	}
	int wait_time_total=0,totalExecutionTime=0,turn_around_time_total=0;
	i=0;	
	while(processes_remaining!=0)
	{
		if(proc[i].remain_time<=quantum_time && proc[i].remain_time>0)
		{
			totalExecutionTime+=proc[i].remain_time;
			proc[i].remain_time = 0;
			flag=1;
		}
		else if(proc[i].remain_time>0)
		{
			proc[i].remain_time-=quantum_time;
			totalExecutionTime+=quantum_time;
		}
		if(flag==1 && proc[i].remain_time==0)
		{
			proc[i].waiting_time=totalExecutionTime-proc[i].arrival_time-proc[i].burst_time;
			wait_time_total+=proc[i].waiting_time;
			
			proc[i].turn_around_time=totalExecutionTime-proc[i].arrival_time;
			turn_around_time_total+=proc[i].turn_around_time;
			flag=0;
			processes_remaining--;
		}

		if(i==n-1)
		{
			i=0;
		}
		else if(proc[i+1].arrival_time<=totalExecutionTime)
			i++;
		else
			i=0;
	}
	printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\n");

	for(i=0;i<n;i++)
	{

		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].process_id,proc[i].burst_time, proc[i].arrival_time, proc[i].waiting_time,proc[i].turn_around_time);
	}
	printf("Average waiting time: %f\n", (float)wait_time_total/n);
	printf("Average turn around time: %f\n",(float)turn_around_time_total/n);

}

