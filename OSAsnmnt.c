#include<stdio.h>
#include<conio.h>

int i=0,j,n;
char ch;
struct process
{
	int p_id, bt, p;
};

void sort_pb(struct process [], int); 	//Sort according to the priority of the process ie priority based
void calculate_avg_tm(struct process [], int);	//to calculate the average time

int main(){
	
	printf("How many Entries:-  ");
	scanf("%d", &n);
	struct process q[n];
	
	for(j=0;j<n;j++){
		q[j].p_id = j+1;
		printf("\nInfo about entry %d", q[j].p_id);
		printf("\nEnter the Burst_Time of entry %d: ", q[j].p_id);
		scanf("%d", &(q[j].bt));
		printf("\nGive the priority of the entry %d: 1.->Teacher/ 0.->Student: ", q[j].p_id);
		scanf("%d", &(q[j].p));
	}

	sort_pb(q, n);

	printf("\nProcess_ID		Burst_Time 	     Priority");
	printf("\n**************************************************************");
	for(i=0;i<n;i++){
		printf("\n%d  				%d  		%d", q[i].p_id, q[i].bt, q[i].p);
	}

	calculate_avg_tm(q,n);

	return 0;
}

void sort_pb(struct process a[],int n){
	struct process tmp;
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j].p < a[j+1].p){
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}


void calculate_TAT(struct process a[], int n, int wait_time[], int TAT[]){
	for(i=0;i<n;i++){
		
		TAT[i] = a[i].bt + wait_time[i];
		
	}
}

void w_time(struct process a[], int n, int wait_time[]){
	wait_time[0] = 0;

	for(i = 1;i<n;i++){
		
		wait_time[i] = wait_time[i-1] + a[i-1].bt;
	}
}

void calculate_avg_tm(struct process a[], int n){
	int wait_time[n], TAT[n], total_wait_time = 0, total_TAT = 0;

	w_time(a, n, wait_time);

	calculate_TAT(a, n, wait_time, TAT);

	for(i=0;i<n;i++){
		
		total_wait_time += wait_time[i];
		total_TAT += TAT[i];
	}

	printf("\n\nProcess_ID	Burst_Time   Waiting_Time   Turn_Around_Time");
	printf("\n**************************************************************");
	for(i=0;i<n;i++){
		
		printf("\n%d		 %d		 %d		 %d", a[i].p_id, a[i].bt, wait_time[i], TAT[i]);
	}

	printf("\n\nAvg Waiting Time: %d", total_wait_time/n);
	printf("\nAvg Turn Around Time: %d\n", total_TAT/n);
}
