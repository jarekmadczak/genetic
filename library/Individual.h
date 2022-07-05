#pragma once
#include <iostream>
class Individual
{

private:
	std::string chromosom;
	int fitness=0;
	

public:

	int getfitness();
	void setfitness(int f);
	void checkFitness();
	void setchromosom(int array_position, char character_to_fill);
	std::string getchromosom();
	void createPopulation();
	Individual createIndividual();
	Individual(std::string chromosom);
	void createChromosom();
	void start();
	float avragefitness();
	void getBestIndividuals();
	void mutatechromosom();
	void NewGeneration();

};

