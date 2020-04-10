#include<stdio.h>
#include<pthread.h>

void *Primenumber (void *args)
 {
	int n,x=0;
	printf("Prime number from 2 to 1000000: \n");
	for (n=2;n<=1000000;n++)
	{		x=0;
		for (int i=1;i<=n;i++)
		{
			if (n% i==0)
				x++;
			if (x>2) break;

		}
		if (x==2)
		printf("%d\n",n);
        }
}

void *fibo(void *args)
{	int x=1,y=1,z=0;
	printf("Fibonaci number sequence from 2 to 1000000: \n");
	
	while(z<=1000000){
		z=x+y;
		x=y;
		y=z;
		printf("%d \n",z);
	}
}
int main () {
	pthread_t thread1;
	pthread_t thread2;
	pthread_create(&thread1, NULL,Primenumber, NULL);
	pthread_create(&thread2, NULL,fibo, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
