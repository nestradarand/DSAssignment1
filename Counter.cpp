#include <iostream>
#include "Counter.h"
#include <string>


using namespace std;

Counter::Counter(){}
Counter::~Counter(){}

void Counter::countIndividual(string str)
{
  for(int i=0;i<str.size();i++)
  {
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
void Counter::countBigrams(string str)
{
  for(int i =0;i<str.size();i += 2)
  {
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
int Counter::getACount()
{
  return aCount;
}
int Counter::getCCount()
{
  return cCount;
}
int Counter::getTCount()
{
  return tCount;
}
int Counter::getGCount()
{
  return gCount;
}
int Counter::getTotalNucleotides()//also gives sum of all line lengths
{
  return totalNucleotides;
}
int Counter::getAACount()
{
  return aaCount;
}
int Counter::getACCount()
{
  return acCount;
}
int Counter::getATCount()
{
  return atCount;
}
int Counter::getAGCount()
{
  return agCount;
}
int Counter::getCACount()
{
  return caCount;
}
int Counter::getCCCount()
{
  return ccCount;
}
int Counter::getCTCount()
{
  return ctCount;
}
int Counter::getCGCount()
{
  return cgCount;
}
void Counter::addLine()
{
  numStrings ++;
}
int Counter::getTotalLines()
{
  return numStrings;
}
float Counter::getAProp()
{
  return float(aCount)/float(totalNucleotides);
}
float Counter::getCProp()
{
  return float(cCount)/float(totalNucleotides);
}
float Counter::getTProp()
{
  return float(tCount)/float(totalNucleotides);
}
float Counter::getGProp()
{
  return float(gCount)/float(totalNucleotides);
}
float Counter::getAAProp()
{
  return float(aaCount)/float(totalBigrams);
}
float Counter::getACProp()
{
  return float(acCount)/float(totalBigrams);
}
float Counter::getATProp()
{
  return float(atCount)/float(totalBigrams);
}
float Counter::getAGProp()
{
  return float(agCount)/float(totalBigrams);
}
float Counter::getCAProp()
{
  return float(caCount)/float(totalBigrams);
}
float Counter::getCCProp()
{
  return float(ccCount)/float(totalBigrams);
}
float Counter::getCTProp()
{
  return float(ctCount)/float(totalBigrams);
}
float Counter::getCGProp()
{
  return float(cgCount)/float(totalBigrams);
}
float Counter::getAverageLineLength()
{
  return float(totalNucleotides)/float(numStrings);
}
void Counter::storeNewLength(int i)
{
  if(lengths.size() <1)
    lengths += std::to_string(i);
  else
  {
    lengths += ",";
    lengths += std::to_string(i);
  }
}
string Counter::getLengths()
{
  return lengths;
}
float Counter::getVariance()
{
  int sum = 0;
  int x;
  string currentValue = "";
  for(int i = 0;i<=lengths.size(); ++i)
  {
    currentValue = "";
    while(lengths[i+1] != ',')
    {
      currentValue += lengths[i++];
    }
    cout <<currentValue<<endl;
    std::basic_istringstream(currentValue) >>x;
    sum += x;
  }
  return float(sum);
}
