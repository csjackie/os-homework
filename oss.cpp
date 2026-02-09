#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cstdlib>

int main(int argc, char **argv) {

	// sets default of n, s, and t to 1 if value not given
        int n = 1;
	int s = 1;
	int t = 1;
	int opt;
	int current = 0;
	int total = 0;

	// getopt(3) to parse options
	while ((opt = getopt(argc, argv, "hn:s:t:")) != -1) {
		switch (opt) {
			// outputs a help message explaining how to run then exits
			case 'h':
				std::cout << "To run: ./oss -n # -s # -t #"
				exit()
				break;
			// number of total child processes
			case 'n':
				// convert and store the value
				n = atoi(optarg);
				break;
			// number of allowed simultaneous child processes being run
			case 's':
				// convert and store the value
				s = atoi(optarg);
				break;
			// number of iterations completed for each child process
			case 't':
				// convert and store the value
				t = atoi(optarg);
				break;
		}
	}

	// validate values are correctly entered
	if (n > 100 || n <= 0) {
		std::cer << "Invalid value for n\n";
		exit(1);
	}
	if (s > 15 || s <= 0) {
		std::cer <<
		exit(1)}
	if (t <= 0){
		exit(1)}
	if (s > n){
		exit(1)}
	
	// while loop to track that the amount of simultaneous child processes is being met
	//while (current < s) {
		//fork();
		//cout << "New child launched";
		//exec("./user", "user", t, NULL)
	//}
	
	// while loop keeps system full until launched all required children
	// while (total < n) {
	// 	wait();
	// 	fork();
	// 	total++;}
	

	return 0;
}
