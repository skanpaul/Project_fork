#include <unistd.h>
#include <stdio.h>
// ------------------------------------
#define FORK_ERROR	-1
#define FORK_CHILD	0
// ------------------------------------
int main(void)
{
	pid_t fk_id;
	int pid_child;
	int pid_parent;

	fk_id = fork();

	if (fk_id == FORK_CHILD)
	{
		pid_child = getpid();
		// printf("\n");
		// printf("==================================\n");
		printf("we are in CHILD\n");
		// printf("==================================\n");
		// printf("fk_id: %d\n", fk_id);
		// printf("PID child: %d\n", pid_child);
		// printf("==================================\n");
		// printf("\n");
	}
	else if (fk_id == FORK_ERROR)
	{
		printf("The forking FAILED\n");
	}
	else // if (fk_id != FORK_CHILD && fk_id != FORK_ERROR) 
	{
		sleep(2);
		pid_parent = getpid();
		pid_child = fk_id;

		// printf("==================================\n");
		printf("we are in PARENT\n");
		// printf("==================================\n");
		// printf("fk_id: %d\n", fk_id);
		// printf("PID parent: %d\n", pid_parent);
		// printf("PID child : %d\n", pid_child);
		// printf("==================================\n");
		// printf("\n");
	}

	
	return 0;
}

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

