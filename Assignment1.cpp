#include <iostream>
#include <fstream>


using namespace std;

int main(int argc, char** argv)
{
  ifstream inputStream;
  inputStream.open("practice.txt");
  if(!inputStream)
  {
    cout << "Error occurred trying to read file" << endl;
    exit(1);
  }
  string x;
  int length;
  //this is working to print out each character from each string
  while(inputStream >> x)
  {
    length = x.size();
    for(int i = 0;i<length;++i)
    {
      char currentChar = x[i];
      cout << currentChar <<endl;
    }
  }
  cout << "File successfully read from" << endl;
  return 0;
}
