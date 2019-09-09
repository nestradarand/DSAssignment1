#include <iostream>
#include <string>
#include <fstream>
#include "Counter.h"

using namespace std;

int main(int args,char** argv)
{
  if(!argv[1])
  {
    cout << "Error, no file name entered." <<endl;
    exit(1);
  }
  Counter* counter = new Counter();
  string fileName = argv[1];
  ifstream inputStream;
  inputStream.open(fileName);
  if(!inputStream)
  {
    cout << "Error occurred trying to read file" << endl;
    exit(1);
  }
  string x;
  int length;
  while(inputStream >> x)
  {
    counter ->countIndividual(x);
    counter -> countBigrams(x);
    counter -> addLine();
  }
  cout << "File successfully read from" << endl;
  cout<< "Total counts:" << endl;
  cout << "A:"<< counter -> getACount() <<endl;
  cout << "T:" << counter-> getTCount() << endl;
  cout << "C:" << counter -> getCCount() << endl;
  cout << "G:" << counter-> getGCount() << endl;

  cout << "Nucleotides: " << counter -> getTotalNucleotides()<<endl;
  cout << "Bigram totals:\n" << "AA:"<< counter -> getAACount() << endl;
  cout << "AC:" << counter ->getACCount() << endl;
  cout << "AT:" << counter -> getATCount() << endl;
  cout << "AG:" << counter -> getAGCount() << endl;
  cout << "CA:"<<counter -> getCACount() << endl;
  cout << "CC:" << counter -> getCCCount() << endl;
  cout << "CT:" << counter ->getCTCount() << endl;
  cout << "CG:" << counter -> getCGCount()<<endl;

  cout << "Total Number of Lines:" << counter -> getTotalLines() << endl;
  cout << "Proportion for A:" << counter ->getAProp() <<endl;
  cout << "Proportion for C:" << counter ->getCProp() <<endl;
  cout << "Proportion for T:" << counter ->getTProp() <<endl;
  cout << "Proportion for G:" << counter ->getGProp() <<endl;

  cout << "Proportion for AA:" << counter ->getAAProp() <<endl;
  cout << "Proportion for AC:" << counter ->getACProp() <<endl;
  cout << "Proportion for AT:" << counter ->getATProp() <<endl;
  cout << "Proportion for AG:" << counter ->getAGProp() <<endl;
  cout << "Proportion for CA:" << counter ->getCAProp() <<endl;
  cout << "Proportion for CC:" << counter ->getCCProp() <<endl;
  cout << "Proportion for CT:" << counter ->getCTProp() <<endl;
  cout << "Proportion for CG:" << counter ->getCGProp() <<endl;



  inputStream.close();
  delete counter;
  return 0;
}
