/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 1
*/
//includes math to use log and cos functionality as well as all other named packages
#include <iostream>
#include "Counter.h"
#include <string>
#include <math.h>

/*Contains all method defintions for coresponding Counter header file*/

using namespace std;
//default constructor; sets the seed for rand based on the system clock
Counter::Counter(){
  srand(time(0));
}
//deconstructor
Counter::~Counter(){}

/*counts the number of a,c,t, and g characters in a given string all other
characters are ignored; also helps keep track of total nucleotides*/
void Counter::countIndividual(string str)
{
  for(int i=0;i<str.size();i++)
  {
    //ensures that all compared chars are lower case
    char x = tolower(str[i]);
    if(x == 'a')
    {
      aCount ++;
      totalNucleotides ++;
    }
    else if(x == 'c')
    {
      cCount ++;
      totalNucleotides ++;
    }
    else if(x == 't')
    {
      tCount ++;
      totalNucleotides ++;
    }
    else if(x == 'g')
    {
      gCount ++;
      totalNucleotides ++;
    }
  }
}
//method to count bigrams in a given string
void Counter::countBigrams(string str)
{
  //increments by two to avoid counting the same bigrams twice
  for(int i =0;i<str.size();i += 2)
  {
    //avoids case sensitivity issues
    char x = tolower(str[i]);
    char y = tolower(str[i+1]);
    if(x == 'a' && y == 'a')
    {
      aaCount ++;
      totalBigrams ++;
    }
    else if(x == 'a' && y == 'c')
      {
        acCount ++;
        totalBigrams ++;
      }
    else if(x == 'a' && y == 't')
    {
      atCount ++;
      totalBigrams ++;
    }
    else if(x == 'c' && y == 'c')
    {
      ccCount ++;
      totalBigrams ++;
    }
    else if(x == 'a' && y == 'g')
    {
      agCount ++;
      totalBigrams ++;
    }
    else if(x == 'c' && y == 'a')
    {
      caCount ++;
      totalBigrams ++;
    }
    else if(x == 'c' && y == 't')
    {
      ctCount ++;
      totalBigrams++;
    }
    else if(x == 'c' && y == 'g')
    {
      cgCount ++;
      totalBigrams ++;
    }
  }
}
//returns int value for count of a nucleotides
int Counter::getACount()
{
  return aCount;
}
//returns int value for count of c nucleotides
int Counter::getCCount()
{
  return cCount;
}
//returns int value for count of t nucleotides
int Counter::getTCount()
{
  return tCount;
}
//returns int value for count of g nucleotides
int Counter::getGCount()
{
  return gCount;
}
//returns int value for total nucleotides count;also used for total length of all lines
int Counter::getTotalNucleotides()
{
  return totalNucleotides;
}
//returns int value for count of aa bigram
int Counter::getAACount()
{
  return aaCount;
}
//returns int value for count of ac bigram
int Counter::getACCount()
{
  return acCount;
}
//returns int value for count of at bigram
int Counter::getATCount()
{
  return atCount;
}
//returns int value for count of ag bigram
int Counter::getAGCount()
{
  return agCount;
}
//returns int value for count of ca bigram
int Counter::getCACount()
{
  return caCount;
}
//returns int value for count of cc bigram
int Counter::getCCCount()
{
  return ccCount;
}
//returns int value for count of ct bigram
int Counter::getCTCount()
{
  return ctCount;
}
//returns int value for count of cg bigram
int Counter::getCGCount()
{
  return cgCount;
}
//increments the count of total number of lines when called
void Counter::addLine()
{
  numLines ++;
}
//returns the total number of lines
int Counter::getTotalLines()
{
  return numLines;
}
//returns the float value of the proportion of a nucleotides in the original file
float Counter::getAProp()
{
  return float(aCount)/float(totalNucleotides);
}
//returns the float value of the proportion of c nucleotides in the original file
float Counter::getCProp()
{
  return float(cCount)/float(totalNucleotides);
}
//returns the float value of the proportion of t nucleotides in the original file
float Counter::getTProp()
{
  return float(tCount)/float(totalNucleotides);
}
//returns the float value of the proportion of g nucleotides in the original file
float Counter::getGProp()
{
  return float(gCount)/float(totalNucleotides);
}
//returns the float value of the proportion of the aa bigrams in the original file
float Counter::getAAProp()
{
  return float(aaCount)/float(totalBigrams);
}
//returns the float value of the proportion of the ac bigrams in the original file
float Counter::getACProp()
{
  return float(acCount)/float(totalBigrams);
}
//returns the float value of the proportion of the at bigrams in the original file
float Counter::getATProp()
{
  return float(atCount)/float(totalBigrams);
}
//returns the float value of the proportion of the ag bigrams in the original file
float Counter::getAGProp()
{
  return float(agCount)/float(totalBigrams);
}
//returns the float value of the proportion of the ca bigrams in the original file
float Counter::getCAProp()
{
  return float(caCount)/float(totalBigrams);
}
//returns the float value of the proportion of the cc bigrams in the original file
float Counter::getCCProp()
{
  return float(ccCount)/float(totalBigrams);
}
//returns the float value of the proportion of the ct bigrams in the original file
float Counter::getCTProp()//works
{
  return float(ctCount)/float(totalBigrams);
}
//returns the float value of the proportion of the cg bigrams in the original file
float Counter::getCGProp()
{
  return float(cgCount)/float(totalBigrams);
}
//returns the double value of the average line length of the lines in the original file
//calculates avarage length of not already done so
double Counter::getAverageLineLength()
{
  if(!avgLineLength||avgLineLength == 0)
    avgLineLength = float(totalNucleotides)/float(numLines);
  return avgLineLength;
}
//calculates the sum of all squared differences between the line lengths and the mean
void Counter::calculateVarianceSum(string str)//works
{
  double newLength = str.size();
  double difference = pow((newLength - getAverageLineLength()),2);
  varSum = varSum+ difference;
}
//returns the variance as a double; calculates it if not already done so
double Counter::getVariance()//works
{
  if(!variance||variance == 0)
    variance = varSum/float(numLines);
  return variance;
}
//returns the standard deviation as a double; calculates it if not already done so
double Counter::getStdDeviation()
{
  if(!stdDeviation||stdDeviation == 0)
    stdDeviation = sqrt(variance);
  return stdDeviation;
}
/*returns double value of random number from gaussian distribution based on
the calculated standard deviation and mean*/
double Counter::calculateGaussianNum()
{
  double a = (double(rand() % 100+.99))/float(100);
  double b = (double(rand() % 100+.99))/float(100);
  double c = sqrt(-2*log(a)) * cos(2*M_PI*b);
  double d = getStdDeviation()*c + getAverageLineLength();
  return d;
}
//resets all member variables from this class to prepare for another file
void Counter::resetStats()
{
  aCount = 0;
  cCount = 0;
  tCount = 0;
  gCount = 0;
  totalNucleotides = 0;

  aaCount = 0;
  acCount = 0;
  atCount = 0;
  agCount = 0;
  caCount = 0;
  ccCount = 0;
  ctCount = 0;
  cgCount = 0;

  totalBigrams = 0;

  numLines = 0;
  avgLineLength = 0;
  varSum = 0;

  variance = 0;
  stdDeviation = 0;
}
