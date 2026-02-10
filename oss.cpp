#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include <stdio.h>

/*
 * This function allows the user to enter the number of total child processes (n),
 * the number of allowed simultaneous processes to be running at one time (s),
 * and the number of total iterations per child process (t). If user enters "-h", 
 * a message is displayed to show user how to run the program.
 *
 * The program then parses through the options and converts each to an integer. 
 * The values of n, s, and t are validated, and program exits if the values are
 * outside the required parameters.
 *
 * The program starts a while loop that launches as many children as allowed, making 
 * sure the simultaneous limit is being reached, while also ensuring the number of
 * needed child processes isn't exceeding the total of child processes launched.
 * Once finished, another while loop waits for one child to finish, and then launches
 * a replacement. This while loop continues until the total of child processes
 * launched reaches the total number of child processes needed. After the while loop
 * completes, the last while loop checks to see if the current running child processes 
 * is greater than 0. If so, the loop waits until all the children are gone.
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
				std::cout << "To run program:\n\t ./oss -n # -s # -t #\n";
				std::cout << "Replace # with an integer.\n";
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
	
	// while loop launches as many child processes as it can, ensuring the number of current running 
	// child processes are less than the allowed simultaneous number of processes, and that the total 
	// number of processes complete is less than the number of total child processes needed
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
			std::cout << "Error! Fork failed.\n";
		}
	}
	
	// while loop keeps system full until launched all required children. Waits for one child to 
	// finish, and then launches a replacement.
	while (total < n) {
	 	// child finishes
		wait(0);
		// decrements current 
	 	current--;
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
		// if childPid is less than 0
		else {
			// display an error message
			std::cout << "Error! Fork failed.\n";
			}

	}
	
	// while loop waits until each child has finished, decrementing current after each one leaves.
	while (current > 0) {
		// child finishes
		wait(0);
		// decrements current
		current--;
	}

	return 0;
}
