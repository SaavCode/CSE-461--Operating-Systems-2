/*
//Nestor Saavedra
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main()
{
	pid_t pid;
	int* status;

	pid = fork();// send to parent

	if (pid > 0) //when parent process
	{
	
		cout << "Parent :child executing" << endl;
		//parent waits for the child
		pid_t cpid = wait(status);//return child pid
		cout << " Parent : child process" << cpid << " finished" << endl;
	}
	if (pid == 0) // give child pid of 0
	{
		for (int i = 0; i<10000; i++)
		{
		//loop to make child wait
		}
		cout << "Child :child exiting" << endl;
		exit(0);//success

	}
	if (pid <= 0)
	{
		cout << "fork failed" << endl;//child was not created
	}
	return 0; // success
}
*/