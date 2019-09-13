#include <iostream>
#include <string>
#include <fstream>
#include "Counter.h"
#include <math.h>

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
  while(inputStream >> x)
  {
    counter ->countIndividual(x);
    counter -> countBigrams(x);
    counter -> addLine();
  }
  //clears the failed state of the stream and seeks the first character
  inputStream.clear();
  inputStream.seekg(0);
  if(!inputStream)
  {
    cout << "Error occurred trying to read file" << endl;
    exit(1);
  }
  while(inputStream >>x)
  {
    counter -> calculateVarianceSum(x);
  }

  cout << "File successfully read from" << endl;
  cout<< "Total counts:" << endl;
  cout << "A:"<< counter -> getACount() <<endl;
  cout << "T:" << counter-> getTCount() << endl;
  cout << "C:" << counter -> getCCount() << endl;
  cout << "G:" << counter-> getGCount() << endl;

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
  cout << "Line length stats:" << endl;
  cout << "Average Line length:" << counter -> getAverageLineLength() <<endl;
  cout << "Total line length:" << counter -> getTotalNucleotides() <<endl;
  cout << "Number of lines: " << counter -> getTotalLines() <<endl;

  cout<< "Variance of line lengths: "<<counter ->getVariance() << endl;
  cout << "Standard Deviation of line length:" << counter ->getStdDeviation() << endl;
  cout << "Gaussian number:" << counter -> calculateGaussianNum() << endl;


  inputStream.close();
  ofstream outputStream;
  outputStream.open("testingWriting.txt");
  srand(time(0));
  for(int i = 0; i <= 1000;++i)
  {
    int newLength = counter ->calculateGaussianNum();
    while(newLength <=0)
      newLength = counter -> calculateGaussianNum();
    int aLength = ceil(newLength*(counter ->getAProp()));
    int cLength  = ceil(newLength*(counter ->getCProp()));
    int tLength = ceil(newLength*(counter -> getTProp()));
    int gLength = ceil(newLength*(counter -> getGProp()));
    outputStream << aLength << "," << cLength << "," << tLength<<","<<gLength<<endl;
    while(aLength > 0||cLength >0||tLength>0||gLength>0)
    {
      int randSelecter = rand()%4;
      if(randSelecter == 0&&aLength>0)
      {
        outputStream << "a";
        aLength -- ;
      }
      else if(randSelecter == 1&&cLength>0)
      {
        outputStream << "c";
        cLength -- ;
      }
      else if(randSelecter == 2&&tLength>0)
      {
        outputStream << "t";
        tLength -- ;
      }
      else if(randSelecter == 3&&gLength>0)
      {
        outputStream << "g";
        gLength -- ;
      }
    }
    outputStream << "\r\n";
  }



  outputStream.close();
  cout << "Done" << endl;
  delete counter;
  return 0;
}
