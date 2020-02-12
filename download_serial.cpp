#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main()
{
	/* The ID of the child process */
	pid_t pid;

	string download_file;
	ifstream infile;
	infile.open("urls.txt");

	int counter = 0;

while(infile >> download_file){
  			pid = fork();


  			if (pid < 0){
  				fprintf(stderr, "Fork Failed");
  				return 1;
  			}

  			else if (pid == 0){

					if(-1 ==	execlp("/usr/bin/wget","wget",download_file.c_str(), NULL)){
						//print the error if it fails
						perror("execlp() failed.\n");
						}

  			}

  			else{
					counter++;
				cout << "Starting Download For File #" << counter  << ": " << download_file << endl;
  			wait(NULL);


  			}
		}
		infile.close();


	return 0;
}
