#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

#include "reservoir.h"
using namespace std;

double get_east_storage(string inputDate) {
  // Opening input file stream
  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }
  string junk;        // new string variable
  getline(fin, junk); // read one line from the file

  string date;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;

  while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration

    fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                          //ignoring the remaining columns
    if (date == inputDate) {
      return eastSt;
    }
  }
  fin.close();
  cout << "Invalid Date Inputted" << endl;
  exit(0);
}

double get_min_east() {
  // Opening input file stream
  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }
  string junk;        // new string variable
  getline(fin, junk); // read one line from the file

  string date;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;

  fin >> date >> eastSt >> eastEl >> westSt >> westEl;
  fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                        //ignoring the remaining columns
  double min = eastSt;
  while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration
    fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                          //ignoring the remaining columns
    if (eastSt < min) {
      min = eastSt;
    }
  }
  fin.close();
  return min;
}

double get_max_east() {
  // Opening input file stream
  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }
  string junk;        // new string variable
  getline(fin, junk); // read one line from the file

  string date;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;

  fin >> date >> eastSt >> eastEl >> westSt >> westEl;
  fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                        //ignoring the remaining columns
  double max = eastSt;
  while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration
    fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                          //ignoring the remaining columns
    if (eastSt > max) {
      max = eastSt;
    }
  }
  fin.close();
  return max;
}

string compare_basins(string inputDate) {
  // Opening input file stream
  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }
  string junk;        // new string variable
  getline(fin, junk); // read one line from the file

  string date;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;

  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration

    fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                          //ignoring the remaining columns
    string higher = "East";
    if (date == inputDate) {
      if (eastEl > westEl) {
        return higher;
      }
      else if (westEl > eastEl) {
        higher = "West";
        return higher;
      }
    }
  }
  cout << "Invalid Date Inputted" << endl;
  exit(0); // or exit(EXIT_SUCCESS);
}
