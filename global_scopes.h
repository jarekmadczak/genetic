#pragma once
#include <math.h>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include <vector>
#include <algorithm>
#include <functional>
int generacja = 0;
float avrage = 0, last_avrage = 0;
int procentage_of_individuals = 10;
int chance_of_mutation = 10;
static int generation = 10;
const std::string geny = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890!@#$%^&*()_-";
std::string target = "";
std::vector<Individual> population;
bool theOne = true;
std::string chromosomToFind = "";
std::string theOneIndividual = "";