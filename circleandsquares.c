#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void forkprocess(double n)
{
  pid_t pid = fork();

  
  if(pid == 0) {
    double area;
    area=3.14*n*n;
    printf("Child process\n");
    printf("Area of Circle is %lg\n",area);
  }
  else if(pid > 0) {
    double area;
    area=n*n;
    printf("Parent process\n");
    printf("Area of square is %lg\n",area);  
  }
  else {
    printf("Unable to create child process.\n");
  }
 
}


int main() {
	
  double n;
  printf("Enter dimension\n");
  scanf("%lg",&n);
  forkprocess(n);
  return 0;
}
