#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>

int main(int argc, char **argv) {

	// sets default of n, s, and t to 1 if value not given
        int n = 1;
	int s = 1;
	int t = 1;
	int opt;
	int current = 0;

	// getopt(3) to parse options
	while ((opt = getopt(argc, argv, "hn:s:t:")) != -1) {
		switch (opt) {
			// outputs a help message explaining how to run then exits
			case 'h':
				cout << "To run: ./oss -n # -s # -t #"
				break;
			// number of total child processes
			case 'n':
				// convert and store the value
				int n = atoi(argv[2]);
				break;
			// number of allowed simultaneous child processes being run
			case 's':
				// convert and store the value
				int s = atoi(argv[4]);
				break;
			// number of iterations completed for each child process
			case 't':
				// convert and store the value
				int t = atoi(argv[6]);
				break;
		}
	}

	// validate values are correctly entered
	// n < 100 && > 0
	// s < 15 && > 0
	// t > 0
	// s <= n

	// while loop to track that the amount of simultaneous child processes is being met
	//while (current < s) {
		//fork();
		//cout << "New child launched";
		//exec(child)
	//}
	
	// while loop keeps system full until launched all required children
	// while (total < n) {
	// 	wait();
	// 	fork();
	// 	total++;}
	

	return 0;
}
