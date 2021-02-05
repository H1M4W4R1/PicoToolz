//
// Created by nov11 on 2/4/2021.
//

#ifndef PROBABILITY_H
#define PROBABILITY_H


#include <cmath>

/*
 * Defines probability of event sequence happening within throwsAmount by single probability
 * Example - if you throw 6-side dice and you want to have specific side eg. 1 and then 2
 * Sequence probability is the basic probability learned at math - 1/6 * 1/6 = 1/36
 * 1 throw  = 0
 * 2 throws = 1/36
 * 3 throws = 1/36 + (35/36) * 1/36 etc.
 * It is almost same as probabilityOfEventInThrows, but takes care of sequenceLength - you need to have at least sequenceLength throws
 * and you can only throw throwsAmount-sequenceLength+1 times (because your sequence must fit in throws).
 * */
double sequenceProbabilityInThrows(int throwsAmount, int sequenceLength, double sequenceProbability)
{
    double sum = 0;
    for(int n = 1; n <= throwsAmount - sequenceLength + 1; n++)
    {
        sum += pow((1-sequenceProbability), n - 1) * sequenceProbability;
    }
    return sum;
}

/*
 * Defines probability of event happening within throwsAmount by single probability
 * Example - if you throw 6-side dice and you want to have specific side eg. 1
 * 1 throw  = 1/6
 * 2 throws = 1/6 + (5/6) * 1/6
 * 3 throws = 1/6 + (5/6) * 1/6 + (5/6)^2 * 1/6 etc.
 * */
double probabilityOfEventInThrows(int throwsAmount, double eventProbabilitySingleThrow)
{
    double sum = 0;
    for(int n = 0; n < throwsAmount; n++)
    {
        // first throw - equal to event probability
        // second throw - first throw failed, check second
        sum += pow((1 - eventProbabilitySingleThrow), n) * eventProbabilitySingleThrow;
    }
    return sum;
}


#endif
