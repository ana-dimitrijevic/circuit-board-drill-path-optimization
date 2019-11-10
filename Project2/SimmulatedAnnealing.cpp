#include "SimmulatedAnnealing.h"


double SimmulatedAnnealing::euclidian_distance(Hole h1, Hole h2) {

	return  sqrt(((h1.x - h2.x) * (h1.x - h2.x)) + ((h1.y - h2.y) * (h1.y - h2.y)));
}

SimmulatedAnnealing::SimmulatedAnnealing() {

	initialize();
}

SimmulatedAnnealing::~SimmulatedAnnealing() {}


double SimmulatedAnnealing::calculate_distance(vector<Hole> path) {

	if (path.size() < 1) return 0;
	
	else {

		double distance = 0;

		for (int i = 1; i < path.size(); i++) {

			distance += euclidian_distance(path[i - 1], path[i]);

		}
			

		return distance;
	}
}

float SimmulatedAnnealing::calculate_acceptance_probability(double energy, double new_energy, double temp) {
	
	if (new_energy < energy)
		return 1.0;

	float exponent = ((energy - new_energy) / temp);

	return exp(exponent);  
}

void SimmulatedAnnealing::swap(vector<Hole>* solution) {
	
	if (solution->size() > 0) {

		int min = 0;
		int max = solution->size() - 1;
		
		int first_swap_element = min + rand() % ((max + 1) - min);
		int second_swap_element = min + rand() % ((max + 1) - min);
		
		std::swap(solution->at(first_swap_element), solution->at(second_swap_element));

	}
}


double SimmulatedAnnealing::run(double temp) {
	
	vector<Hole> optimal_path = vector<Hole>(currentSolution);
	double dropdown_factor = 0.0006;

	while (temp > 1) {
		
		vector<Hole> possible_path = vector<Hole>(currentSolution);

		swap(&possible_path);

		
		double currentEnergy = calculate_distance(currentSolution);
		double neighbourEnergy = calculate_distance(possible_path);

		if (calculate_acceptance_probability(currentEnergy, neighbourEnergy, temp) > 
			static_cast <float> (rand()) / static_cast <float> (RAND_MAX) )
		{
			currentSolution = vector<Hole>(possible_path);
		}

		if (calculate_distance(currentSolution) < calculate_distance(optimal_path))
			optimal_path = vector<Hole>(currentSolution);

		
		temp *= 1 - dropdown_factor;
	}


	currentSolution = vector<Hole>(optimal_path);

	//for(int i=0; i< optimal_path.size(); i++)
		//std::cout << "(" << optimal_path[i].x << "," << optimal_path[i].y << ") ";

	return calculate_distance(currentSolution);
}

void SimmulatedAnnealing::initialize() {

	currentSolution.push_back(*(new Hole(62.0, 58.4)));
	currentSolution.push_back(*(new Hole(57.5, 56.0)));
	currentSolution.push_back(*(new Hole(51.7, 56.0)));
	currentSolution.push_back(*(new Hole(67.9, 19.6)));
	currentSolution.push_back(*(new Hole(57.7, 42.1)));
	currentSolution.push_back(*(new Hole(54.2, 29.1)));
	currentSolution.push_back(*(new Hole(46.0, 45.1)));
	currentSolution.push_back(*(new Hole(34.7, 45.1)));
	currentSolution.push_back(*(new Hole(45.7, 25.1)));
	currentSolution.push_back(*(new Hole(34.7, 26.4)));
	currentSolution.push_back(*(new Hole(28.4, 31.7)));
	currentSolution.push_back(*(new Hole(33.4, 60.5)));
	currentSolution.push_back(*(new Hole(22.9, 32.7)));
	currentSolution.push_back(*(new Hole(21.5, 45.8)));
	currentSolution.push_back(*(new Hole(15.3, 37.8)));
	currentSolution.push_back(*(new Hole(15.1, 49.6)));
	currentSolution.push_back(*(new Hole(9.1, 52.8)));
	currentSolution.push_back(*(new Hole(9.1, 40.3)));
	currentSolution.push_back(*(new Hole(2.7, 56.8)));
	currentSolution.push_back(*(new Hole(2.7, 33.1)));


}
