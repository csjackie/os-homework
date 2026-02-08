#include <iostream>
#include <unistd.h>
#include <cstdlib>

int main(int argc, char *argv[]) {
	int t = atoi(argv[1]);
	for (int i = 1; i <= t; i++) {
		std::cout << "USER PID: " << getpid() << " PPID: " << getppid() << " Iteration: " << i << " before sleeping\n";
		sleep(1);
		std::cout << "USER PID: " << getpid() <<  " PPID: " << getppid() << " Iteration: " << i <<  " after sleeping\n";
	}
	return 0;
}

