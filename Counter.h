#ifndef COUNTER_H
#define COUNTER_H
#include <string>

class Counter
{
  int aCount = 0;
  int cCount = 0;
  int tCount = 0;
  int gCount = 0;
  int totalNucleotides = 0;

  int aaCount = 0;
  int acCount = 0;
  int atCount = 0;
  int agCount = 0;
  int caCount = 0;
  int ccCount = 0;
  int ctCount = 0;
  int cgCount = 0;

  int totalBigrams;

  int numStrings = 0;
public:
  Counter();
  ~Counter();
  void countIndividual(std::string str);
  void countBigrams(std::string str);
  int getACount();
  int getCCount();
  int getTCount();
  int getGCount();
  int getTotalNucleotides();

  int getAACount();
  int getACCount();
  int getATCount();
  int getAGCount();

  int getCACount();
  int getCCCount();
  int getCTCount();
  int getCGCount();


  void addLine();
  int getTotalLines();

  float getAProp();
  float getCProp();
  float getTProp();
  float getGProp();

  float getAAProp();
  float getACProp();
  float getATProp();
  float getAGProp();

  float getCAProp();
  float getCCProp();
  float getCTProp();
  float getCGProp();


};

#endif
