#pragma once
#include<iostream>
#include <stdlib.h> 
#include <math.h> 
#include <vector> 
#include<algorithm>
#include "Hole.h"

using namespace std;

class SimmulatedAnnealing {

private:
	vector<Hole> currentSolution;

public:
	SimmulatedAnnealing();
	~SimmulatedAnnealing();

	void initialize();

	double run(double temperature);
	
	float calculate_acceptance_probability(double energy, double newEnergy, double temperature);
	void swap(vector<Hole>* sol);

	double calculate_distance(vector<Hole> sol);

	double euclidian_distance(Hole h1, Hole h2);
};
