#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int acount = 0;
int ccount = 0;
int tcount = 0;
int gcount = 0;

void countLetters(string fileName);

int main(int argc, char** argv)
{

  countLetters(argv[1]);
  cout << "File successfully read from" << endl;
  cout<< "Total counts:" << endl;
  cout << acount <<endl;
  cout << ccount << endl;
  cout <<tcount << endl;
  cout <<gcount << endl;
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
  char x;
  int length;
  while(inputStream >> x)
  {
    if(x == 'a')
      acount ++;
    else if(x == 'c')
      ccount ++;
    else if(x == 't')
      tcount++;
    else if(x == 'g')
      gcount++;
    cout << x<< endl;
  }

}
