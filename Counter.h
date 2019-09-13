/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 1
*/
#ifndef COUNTER_H
#define COUNTER_H
#include <string>

//header file for Counter class
/*This class takes care of all the computations regarding counting and
determining statistics for text files containing nucleotide sequences*/
class Counter
{
  //these counts are for each individual nucleotide
  int aCount = 0;
  int cCount = 0;
  int tCount = 0;
  int gCount = 0;
  //member variable to track total nucleotides
  int totalNucleotides = 0;

  //member variables to track the bigram counts
  int aaCount = 0;
  int acCount = 0;
  int atCount = 0;
  int agCount = 0;
  int caCount = 0;
  int ccCount = 0;
  int ctCount = 0;
  int cgCount = 0;
  //stores the total number of bigrams
  int totalBigrams =0;
  //stores total number of lines and their average length
  int numLines = 0;
  double avgLineLength;
  //stores numerator for calculating variance
  float varSum = 0;
  //stores variance and standard deviation
  double variance;
  double stdDeviation;


public:
  //default constructor
  Counter();
  //deconstructor
  ~Counter();
  //counts individual nucleotides
  void countIndividual(std::string str);
  //counts bigrams in each line
  void countBigrams(std::string str);
  //return nucleotide counts for respective nucleotide
  int getACount();
  int getCCount();
  int getTCount();
  int getGCount();
  int getTotalNucleotides();

  //return bigram counts for A bigrams
  int getAACount();
  int getACCount();
  int getATCount();
  int getAGCount();

  //return bigram counts for C bigrams
  int getCACount();
  int getCCCount();
  int getCTCount();
  int getCGCount();

  //adds to count of lines
  void addLine();
  //returns total lines
  int getTotalLines();
  //returns relative proportion for each a,c,t,g nucleotides
  float getAProp();
  float getCProp();
  float getTProp();
  float getGProp();
  //return relative proportion for A bigrams
  float getAAProp();
  float getACProp();
  float getATProp();
  float getAGProp();
  //return relative proportion for C bigrams
  float getCAProp();
  float getCCProp();
  float getCTProp();
  float getCGProp();
  //returns average line length
  double getAverageLineLength();
  //calculates variance numerator
  void calculateVarianceSum(std::string str);
  //returns the stored variance
  double getVariance();
  //returns the stored standard deviation
  double getStdDeviation();
  //returns double value for calculated number from gaussian distribution
  double calculateGaussianNum();
  //resets all member variables to zero for next calculations
  void resetStats();
};

#endif
