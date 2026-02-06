#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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
			case 'h':
				// outputs a help message explaining how to run then exit
				break;
			case 'n':
				// convert and store the value
				// number of total child processes
				break;
			case 's':
				// convert and store the value
				// number of allowed simultaneous child processes being run
				break;
			case 't':
				// convert and store the value
				// number of iterations completed for each child process
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
