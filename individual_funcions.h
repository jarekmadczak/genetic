#include "Individual.h"
#include "global_scopes.h"
#pragma once

Individual::Individual(std::string chromosome) {
	chromosom = chromosome;
}

void Individual::createChromosom() {


	char ch = ' ';
	for (int i = 0; i < target.size(); i++) {	
	int random = rand() % geny.length() +0;
	ch = geny[random];
		setchromosom(i, ch);
	}

}

void Individual::setchromosom(int array_position, char character_to_fill) {
	chromosom[array_position] = character_to_fill;
}

std::string Individual::getchromosom() {
	return chromosom;
}
void Individual::createPopulation()
{
	srand(time(0));
	for (int i = 0; i < generation; i++) {
		population.push_back(createIndividual());
	}
	
}

Individual Individual::createIndividual()
{
	
	createChromosom();
	chromosom = getchromosom();
	Individual individual(chromosom);
	return individual;
}

float Individual::avragefitness()
{
	float avrages = avrage/generation;
	return avrages;
}

bool compareInterval(Individual i1, Individual i2)
{
	return (i1.getfitness() < i2.getfitness());
}
 void Individual::getBestIndividuals()
 {
	 
	std::sort(population.begin(),population.end(),compareInterval);
	
}

int Individual::getfitness()
{
	return fitness;
}

void Individual::setfitness(int f  )
{
fitness = f;
	
}

void Individual::checkFitness() {
	int f = 0;
	
		for (int i = 0; i < chromosom.length(); i++) {
			if (chromosom[i] != target[i]) {
				f++;
				
			}
			
			

		}
		setfitness(f);
		fitness = f;
		
		std::cout << getfitness() << "   " << getchromosom() << std::endl;
		if ( fitness==0)  {
			theOne = false;
			std::cout << "found this one -----> " << getchromosom() << " <--------- found this one"<<std::endl;
			theOneIndividual = getchromosom();
		}
		avrage = avrage + f;
		
}
Individual combinechromosom(Individual i1,Individual i2) {
	std::string chromosom1 =i1.getchromosom();
	Individual copy = i1;
	int fitness_before = i1.getfitness();
	std::string chromosom2 = i2.getchromosom();
	do {


		for (int i = 0; i < target.size(); i++) {
			int random = rand() % target.size();

			i1.setchromosom(i, chromosom2[random]);
			i1.checkFitness();


		}
		if (i1.getfitness() > fitness_before) {
			i1 = copy;
			i1.mutatechromosom();
		}
	} while (i1.getfitness() > fitness_before);
	

		int mutation = rand() % 100;
	
	if (chance_of_mutation <= mutation) {
			i1.mutatechromosom();
			i2.mutatechromosom();
		}
	if (last_avrage == avrage) {
		i1.mutatechromosom();
		i2.mutatechromosom();
	}
	return i1;
}
void copyIndivuals() {
	for (int i = procentage_of_individuals; i < generation; i++) {
		population.pop_back();
	}
	for (int i = 0; i < generation;i++) {

		population.push_back(population[i]);
	}
	for (int i = 0; i < generation-1; i++) {
		int random = rand() % generation;
		population.pop_back();
		population[i]=(combinechromosom(population[i], population[random]));
	}
	
}

void Individual::mutatechromosom() {
	int random = rand() % geny.length() + 0;
	int rands= rand() % target.size()+ 0;
	int ch = geny[random];
	setchromosom(rands, ch);

}

 void Individual::NewGeneration()
{
	getBestIndividuals();
	copyIndivuals();
	last_avrage = avrage;
	avrage = 0;
	generacja++;
	for (int i = 0; i < generation; i++) {
		population[i].checkFitness();
	}
	
	std::cout << "generation: " << generacja << "   fitness: " << avragefitness() << std::endl;
	
}





void Individual::start(){
	
	createPopulation();
	for (int i = 0; i < generation; i++) {
		 population[i].checkFitness();
	}
	do {
	NewGeneration();
	} while (theOne);
	
	
	std::cout << "program found word : " << theOneIndividual <<"  in generation "<<generacja<< std::endl;
	
 
}



