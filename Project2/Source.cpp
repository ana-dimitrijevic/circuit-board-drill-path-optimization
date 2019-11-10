#include"SimmulatedAnnealing.h"


int main(int argc, char* argv[]) {

	int N = 20;
	double min_distance = 99999.9;

	for (int i = 0; i < N; i++) {

		SimmulatedAnnealing* simAnnealing = new SimmulatedAnnealing();
		double distance = simAnnealing->run(50000);
		std::cout << i << ". distance= " << distance << endl;
		if (distance < min_distance) min_distance = distance;
	}

	std::cout << "Minimum distance= " << min_distance << endl;

	return 0;
}