/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 1
*/
//the following are included to write to/read from files and import the Counter class
#include <iostream>
#include <string>
#include <fstream>
#include "Counter.h"
#include <math.h>

using namespace std;

//main method to allow user to store statistics for a given text file of DNA sequences
int main(int args,char** argv)
{
  //ensures that argument specifying file name was used at run-time
  if(!argv[1])
  {
    cout << "Error, no file name entered." <<endl;
    exit(1);
  }
  Counter* counter = new Counter();
  string fileName = argv[1],x;
  ifstream inputStream;
  ofstream outputStream;
  //boolean to help dictate when the main loop is running
  bool going = true;
  //open and initial output file and write all necessary information
  outputStream.open("Estrada-Rand_Noah.txt");
  outputStream << "Noah Estrada-Rand\r\nID:2272490\r\nEmail:estra146@mail.chapman.edu\r\n";
  outputStream << "Course Number: 350-01\r\nAssignment: Assignment 1\r\n";
  //main loop
  while(going)
  {
    inputStream.open(fileName);
    //ensures successful input stream established
    //reference: stack overflow
    if(!inputStream)
    {
      cout << "Error occurred trying to read file." << endl;
      exit(1);
    }
    //ensures successful output stream etablished
    //reference: stack overflow
    if(!outputStream)
    {
      cout << "File unable to be written to."<<endl;
      exit(1);
    }
    //seed pseudorandom number generator
    srand(time(0));
    //while loop to read all contents of file until there are none left
    while(inputStream >> x)
    {
      //counts individual nucleotides, bigrams, and number of lines
      counter ->countIndividual(x);
      counter -> countBigrams(x);
      counter -> addLine();
    }
    //clears the failed state of the stream and seeks the first character of the file
    //reference: stack overflow
    inputStream.clear();
    inputStream.seekg(0);
    //iterate through file again to calculate the numerator of the variance calculation
    while(inputStream >>x)
    {
      counter -> calculateVarianceSum(x);
    }
    //close inputStream
    inputStream.close();
    //the following lines print the statistical results to the output file
    outputStream << "File Read From: " << fileName<<"\r\n";
    outputStream<< "Nucleotide counts: " << "\r\n";
    outputStream << "A: "<< counter -> getACount() <<"\r\n";
    outputStream << "T: " << counter-> getTCount() << "\r\n";
    outputStream << "C: " << counter -> getCCount() << "\r\n";
    outputStream << "G: " << counter-> getGCount() << "\r\n";

    outputStream << "Bigram totals:\r\n" << "AA: "<< counter -> getAACount() << "\r\n";
    outputStream << "AC: " << counter ->getACCount() << "\r\n";
    outputStream << "AT: " << counter -> getATCount() << "\r\n";
    outputStream << "AG: " << counter -> getAGCount() << "\r\n";
    outputStream << "CA: "<<counter -> getCACount() << "\r\n";
    outputStream << "CC: " << counter -> getCCCount() << "\r\n";
    outputStream << "CT: " << counter ->getCTCount() << "\r\n";
    outputStream << "CG: " << counter -> getCGCount()<<"\r\n";

    outputStream << "Total Number of Lines: " << counter -> getTotalLines() << "\r\n";
    outputStream << "Proportion for A: " << counter ->getAProp() <<"\r\n";
    outputStream << "Proportion for C: " << counter ->getCProp() <<"\r\n";
    outputStream << "Proportion for T: " << counter ->getTProp() <<"\r\n";
    outputStream << "Proportion for G: " << counter ->getGProp() <<"\r\n";

    outputStream << "Proportion for AA: " << counter ->getAAProp() <<"\r\n";
    outputStream << "Proportion for AC: " << counter ->getACProp() <<"\r\n";
    outputStream << "Proportion for AT: " << counter ->getATProp() <<"\r\n";
    outputStream << "Proportion for AG: " << counter ->getAGProp() <<"\r\n";
    outputStream << "Proportion for CA: " << counter ->getCAProp() <<"\r\n";
    outputStream << "Proportion for CC: " << counter ->getCCProp() <<"\r\n";
    outputStream << "Proportion for CT: " << counter ->getCTProp() <<"\r\n";
    outputStream << "Proportion for CG: " << counter ->getCGProp() <<"\r\n";
    outputStream << "Line length statistics: " << "\r\n";
    outputStream << "Average Line length: " << counter -> getAverageLineLength() <<"\r\n";
    outputStream << "Total line length: " << counter -> getTotalNucleotides() <<"\r\n";
    outputStream << "Number of lines: " << counter -> getTotalLines() <<"\r\n";

    outputStream<< "Variance of line lengths: "<<counter ->getVariance() << "\r\n";
    outputStream << "Standard Deviation of line length: " << counter ->getStdDeviation() << "\r\n\r\n";

    /*first a number from the gaussian distribution is calculated based on the
    mean and standard deviation calculated from the initial text file;
    the while loop ensures that the number is recalculated until it is greater than
    zero; ceil() is used to ensure that the round off of the product of
    the length of the line to be printed and the relative proportion of each
    nucleotide does not default to zero given the fact that integer math is used*/
    for(int i = 0; i < 1000;++i)
    {
      int newLength = counter ->calculateGaussianNum();
      while(newLength <=0)
        newLength = counter -> calculateGaussianNum();
      int aLength = ceil(newLength*(counter ->getAProp()));
      int cLength  = ceil(newLength*(counter ->getCProp()));
      int tLength = ceil(newLength*(counter -> getTProp()));
      int gLength = ceil(newLength*(counter -> getGProp()));
      /*this while loop randomly generates a number between one and 4; integer
      arithmetic is then used to truncate any decimal values, yielding numbers
      from 0 to 3; if a letters corresponding number is calcualted then
      it is printed to the output file and its relative count decremented;
      this process repeats until all counts are depleted, ensuring the same relative
      proportion for each line as the original text file*/
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
    //statistics are reset for the counter class in preparation for next file
    counter -> resetStats();
    cout << fileName << " successfully read from.\nContents stored to Estrada-Rand_Noah.txt" <<endl;
    char response;
    cout << "Would you like to read in another file of DNA sequences?"<<endl;
    cout << "Type 'y' to continue or 'n' to stop: ";
    cin >>response;
    response = tolower(response);
    //until y or n is entered, the user will be prompted until they answer yes or not to continuing
    while(response != 'n'&&response != 'y')
    {
      cout<< "Invalid command entered. Try again." <<endl;
      cin >> response;
    }
    if(response == 'n')
    {
      going  = false;//breaks the initial while loop and ends programs
      break;
    }
    else if(response  == 'y')
    {
      //prompt user for new file name to read in
      cout << "Type the name of the file you would like to use next: " <<endl;
      cin >>fileName;
    }
  }
  //closes filestream
  outputStream.close();
  cout << "Application closed." << endl;
  //deallocates memory alloted to Counter object
  delete counter;
  return 0;
}
