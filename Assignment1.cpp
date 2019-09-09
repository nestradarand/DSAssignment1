#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int aCount = 0;
int cCount = 0;
int tCount = 0;
int gCount = 0;

int aaCount = 0;
int acCount = 0;
int atCount = 0;
int agCount = 0;
int caCount = 0;
int ccCount = 0;
int ctCount = 0;
int cgCount = 0;

int numStrings = 0;
int totalNucleotides = 0;

void countLetters(string fileName);
int getSum(int one,int two,int three,int four);
void countIndividual(string str);
void countBigrams(string str);

int main(int argc, char** argv)
{
  if(!argv[1])
  {
    cout << "Error, no file name entered." <<endl;
    exit(1);
  }
  countLetters(argv[1]);
  cout << "File successfully read from" << endl;
  cout<< "Total counts:" << endl;
  cout << aCount <<endl;
  cout << cCount << endl;
  cout <<tCount << endl;
  cout <<gCount << endl;
  cout << "Sum:" << getSum(aCount,cCount,tCount,gCount)<< " Nucleotides"<<endl;
  cout << "Bigram totals:\n" << "AA:"<< aaCount << endl;
  cout << "AC:" << acCount << endl;
  cout << "AT:" << atCount << endl;
  cout << "AG:" << agCount << endl;
  cout << "CA:"<<caCount << endl;
  cout << "CC:" << ccCount << endl;
  cout << "CT:" << ctCount << endl;
  cout << "CG:" << cgCount<<endl;
  cout<<"Total Number of Strings:" << numStrings <<endl;

  return 0;
}
void countLetters(string fileName)
{
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
    countIndividual(x);
    countBigrams(x);
    numStrings++;
    cout << x<< endl;
  }
  inputStream.close();
}
int getSum(int one,int two,int three,int four)
{
  int sum = one+two+three+four;
  return sum;
}
void countIndividual(string str)
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
void countBigrams(string str)
{
  for(int i =0;i<str.size();i++)
  {
    char x = tolower(str[i]);
    char y = tolower(str[i+1]);
    if(x == 'a' && y == 'a')
      aaCount ++;
    else if(x == 'a' && y == 'c')
      acCount ++;
    else if(x == 'a' && y == 't')
      atCount ++;
    else if(x == 'c' && y == 'c')
      ccCount ++;
    else if(x == 'a' && y == 'g')
      agCount ++;
    else if(x == 'c' && y == 'a')
      caCount ++;
    else if(x == 'c' && y == 't')
      ctCount ++;
    else if(x == 'c' && y == 'g')
      cgCount ++;
  }
}
