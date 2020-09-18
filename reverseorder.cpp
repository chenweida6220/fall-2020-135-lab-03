#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

#include <sstream>

#include "reverseorder.h"
using namespace std;

void reverse_order(string date1, string date2){
  string date;
  double eastSt, eastEl, westSt, westEl;
  bool checker = false;
  string dateArray[365];
  double westElArray[365];
  int count = 0;

  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1);
  }

    string junk;
    getline(fin, junk);

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
        fin.ignore(INT_MAX, '\n');

        if (date == date1){
            checker = true;
        }
        if (checker == true){
          dateArray[count] = date;
            westElArray[count] = westEl;
            count++;
            if (date == date2){
                checker = false;
            }
        }

    }
    fin.close();
    for (int x = count - 1; x >= 0; x--){
        cout << dateArray[x] << " " << westElArray[x] << " ft"<< endl;
    }

}
