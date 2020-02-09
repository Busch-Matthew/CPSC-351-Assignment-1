#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	/* The command buffer */
	string cmdBuff;

	/* The ID of the child process */
	pid_t pid;
	string path;
	string command;
	/* Keep running until the user has typed "exit" */
	do
	{
		/* Prompt the user to enter the command */
		cerr << "cmd>";
		cin >> cmdBuff;

		/* If the user wants to exit */
		if(cmdBuff != "exit")
		{
			/* TODO: Create a child */
			command = cmdBuff.c_str();
			pid = fork();


			if (pid < 0){
				fprintf(stderr, "Fork Failed");
				return 1;
			}

			else if (pid == 0){

				path = "/bin/" + command;

				//checking if the execlp() fails
				//based on an example found on stackoverflow
				if(-1 ==	execlp(path.c_str(), command.c_str(), NULL)){
					//print the error if it fails
					perror("execlp() failed.\n");
				}
			}

			else{
				wait(NULL);
				cout << "Child Complete" << endl;
			}
		}
	}
	while(cmdBuff != "exit");

	return 0;
}
