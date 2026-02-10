#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include <stdio.h>

/*
 * This function accepts 
 *
*/


int main(int argc, char **argv) {
	
	// sets default of n, s, and t to 1 if value not given
        int n = 1;
	int s = 1;
	int t = 1;
	// initializing opt
	int opt;
	// accumulator to track current child processes being completed, set at 0
	int current = 0;
	// accumulator to track the total number of child processes launched, set at 0
	int total = 0;

	// getopt(3) parses options
	while ((opt = getopt(argc, argv, "hn:s:t:")) != -1) {
		switch (opt) {
			// outputs a help message explaining how to run the program, then exits
			case 'h':
				std::cout << "To run: ./oss -n # -s # -t #";
				exit(0);
				break;
			// number of total child processes
			case 'n':
				// converts the string input for n to int and assigns it to n
				n = atoi(optarg);
				break;
			// number of allowed simultaneous child processes running at one time
			case 's':
				// converts the string input for s to int and assigns it to s
				s = atoi(optarg);
				break;
			// number of iterations for each child process
			case 't':
				// converts the string input for t to int and assigns it to t
				t = atoi(optarg);
				break;
		}
	}

	// prints error message and exits program if the value of n, s, or t are out of range
	if (n <= 0 || n > 100) {
		std::cout << "Invalid value for n\n";
		exit(1);
	}

	if (s <= 0 || s > 15) {
		std::cout << "Invalid value for s\n";
		exit(1);
	}

	if (t <= 0){
		std::cout << "Invalid value for t\n";
		exit(1);
	}

	if (s > n){
		exit(1);
	}
	
	// while loop keeps track to ensure the number of current running child processes are less than 
	// the allowed simultaneous number of processes, and that the total number of processes completed
	// is less than the number of total child processes needed
	while (current < s && total < n) {
		// forks the parent process, assigns pid to childPid
		pid_t childPid = fork();
		// create character array
		char t_string[10];
		// convert t into a string (t_string)
		sprintf(t_string, "%d", t);
		// if childPid is equal to 0 (confirms this is the child process)
		if (childPid == 0) {
			// child launches exec
			execl("./user", "user", t_string, NULL);
		}
		// if childPid is greater than 0 (confirms this is the parent process)
		else if (childPid > 0) {
			// shows output of new child being launched
			std::cout << "New child launched\n";
			// increments the current number of child processes running
			current++;
			// increments the total number of child processes launched
			total++;
		}
		// if the childPid is < 0, there has been an error - print message
		else {
			std::cout << "Error! Fork failed.";
		}
	}
	
	// while loop keeps system full until launched all required children
	while (total < n) {
	 	wait(0);
	 	current--;
	 	pid_t childPid = fork();
		// create character array
		char t_string[10];
		// convert t into a string (t_string)
		sprintf(t_string, "%d", t);
		// if childPid is equal to 0 (confirms this is the child process)
		if (childPid == 0) {
			// child launches exec
			execl("./user", "user", t_string, NULL);
		}
		// if childPid is greater than 0 (confirms this is the parent process)
		else if (childPid > 0) {
			// shows output of new child being launched
			std::cout << "New child launched\n";
			// increments the current number of child processes running
			current++;
			// increments the total number of child processes launched
			total++;
		}
		else {
			std::cout << "Error! Fork failed.";
			}

	}
	
	// while loop 
	while (current > 0) {
		wait(0);
		current--;
	}

	return 0;
}
