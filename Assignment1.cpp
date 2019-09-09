#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int acount = 0;
int ccount = 0;
int tcount = 0;
int gcount = 0;

int aacount = 0;
int account = 0;
int atcount = 0;
int agcount = 0;
int cacount = 0;
int cccount = 0;
int ctcount = 0;
int cgcount = 0;

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
  cout << acount <<endl;
  cout << ccount << endl;
  cout <<tcount << endl;
  cout <<gcount << endl;
  cout << "Sum:" << getSum(acount,ccount,tcount,gcount)<< " Nucleotides"<<endl;
  cout << "Bigram totals:\n" << "AA:"<< aacount << endl;
  cout << "AC:" << account << endl;
  cout << "AT:" << atcount << endl;
  cout << "AG:" << agcount << endl;
  cout << "CA:"<<cacount << endl;
  cout << "CC:" << cccount << endl;
  cout << "CT:" << ctcount << endl;
  cout << "CG:" << cgcount<<endl;

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
      acount ++;
      totalNucleotides ++;
    }
    else if(x == 'c')
    {
      ccount ++;
      totalNucleotides ++;
    }
    else if(x == 't')
    {
      tcount ++;
      totalNucleotides ++;
    }
    else if(x == 'g')
    {
      gcount ++;
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
      aacount ++;
    else if(x == 'a' && y == 'c')
      account ++;
    else if(x == 'a' && y == 't')
      atcount ++;
    else if(x == 'a' && y == 'g')
      agcount ++;
    else if(x == 'c' && y == 'a')
      cacount ++;
    else if(x == 'c' && y == 'c')
      ccount ++;
    else if(x == 'c' && y == 't')
      ctcount ++;
    else if(x == 'c' && y == 'g')
      cgcount ++;
  }
}
