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


			/* TODO: Error check to make sure the child was successfully created */
			if (pid < 0){
				fprintf(stderr, "Fork Failed");
				return 1;
			}
			/*** TODO: If I am child, I will do this: ****/

			else if (pid == 0){

				path = "/bin/" + command;

				//checking if the execlp() fails
				//based on an example found on stackoverflow
				if(-1 ==	execlp(path.c_str(), command.c_str(), NULL)){
					//print the error if it fails
					perror("execlp() failed.\n");
				}
			}
			/* Call execlp() to replace my program with that specified at the command line.
			 * PLEASE NOTE: YOU CANNOT PASS cmdBuff DIRECTLY to execlp(). It is because
			 * cmdBuff is an object of type string (i.e., a class) and execlp() expects
 			 * an array of characters.  However, you can pass cmdBuff.c_str(), which will
			 * return an array of characters representation of the string object.
			 *
			 * Also, please do not forget to error check your exelp() system calls.
			 */


			/*** TODO: If I am a parent, I will do the following ***?

			/* Wait for the child process to terminate */
			else{
				wait(NULL);
				cout << "Child Complete" << endl;
			}
		}
	}
	while(cmdBuff != "exit");

	return 0;
}
