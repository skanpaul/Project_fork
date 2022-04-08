#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
// ------------------------------------
#define FORK_ERROR	-1
#define FORK_CHILD	0
// ------------------------------------
int is_fork_parent(pid_t fk_id)
{
	if (fk_id != FORK_CHILD && fk_id != FORK_ERROR)
		return 1; 	// YES
	else
		return 0; 		// NO
}

// ------------------------------------
int main(void)
{
	pid_t fk_id;

	fk_id = fork();
	int n;

	if (fk_id == FORK_CHILD)
	{
		printf("CHILD process | own PID: %d | parent PID: %d\n", getpid(), getppid());
	}
	else if (is_fork_parent(fk_id))
	{
		wait(NULL);
		printf("PARENT process| own PID: %d | parent PID: %d\n", getpid(), getppid());
	}
	return 0;
}
// ------------------------------------
// int main(void)
// {
// 	pid_t fk_id;

// 	fk_id = fork();
// 	int n;

// 	if (fk_id == FORK_CHILD)
// 		n = 10;
// 	else if (is_fork_parent(fk_id))
// 		n = 20;

// 	if (is_fork_parent(fk_id))
// 		wait(NULL);

// 	for (int i = n; i < n + 6; i++)
// 		printf("%d ", i);	

// 	return 0;
// }
// ------------------------------------
// int main(void)
// {
// 	pid_t fk_id;

// 	fk_id = fork();

// 	if (is_fork_parent(fk_id))
// 	{
// 		fk_id = fork();

// 		if (is_fork_parent(fk_id))
// 		{
// 			fk_id = fork();
		
// 			if (is_fork_parent(fk_id))
// 			{
// 				fk_id = fork();
// 			}
// 		}
// 	}

// 	printf("Salut\n");
// 	return 0;
// }

// ------------------------------------
// int main(void)
// {
// 	pid_t fk_id;
// 	int pid_child;
// 	int pid_parent;

// 	fk_id = fork();

// 	if (fk_id == FORK_CHILD)
// 	{
// 		pid_child = getpid();
// 		printf("\n");
// 		printf("==================================\n");
// 		printf("we are in CHILD\n");
// 		printf("==================================\n");
// 		printf("fk_id: %d\n", fk_id);
// 		printf("PID child: %d\n", pid_child);
// 		printf("==================================\n");
// 		printf("\n");
// 	}
// 	else if (fk_id == FORK_ERROR)
// 	{
// 		printf("The forking FAILED\n");
// 	}
// 	else // if (fk_id != FORK_CHILD && fk_id != FORK_ERROR) 
// 	{
// 		sleep(2);
// 		pid_parent = getpid();
// 		pid_child = fk_id;

// 		printf("==================================\n");
// 		printf("we are in PARENT\n");
// 		printf("==================================\n");
// 		printf("fk_id: %d\n", fk_id);
// 		printf("PID parent: %d\n", pid_parent);
// 		printf("PID child : %d\n", pid_child);
// 		printf("==================================\n");
// 		printf("\n");
// 	}	
// 	return 0;
// }

// ------------------------------------
// int main(void)
// {
// 	pid_t fk_id;

// 	fk_id = fork();

// 	printf("hello world\n");
// 	printf("fork id: %d\n", fk_id);

// 	return 0;
// }
// ------------------------------------

