#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"
using namespace std;

int main() {
  double user_eastSt = get_east_storage("05/20/2018");
  cout << user_eastSt << " billion gallons" << endl;
  // Output: 80.96 billion gallons
  user_eastSt = get_east_storage("01/01/2018");
  cout << user_eastSt << " billion gallons" << endl;
  // Output: 59.94 billion gallons

  cout << endl;

  double min_eastSt = get_min_east();
  cout << "Minimum storage in East basin: " << min_eastSt << " billion gallons" << endl;
  // Output: Minimum storage in East basin: 59.88 billion gallons
  double max_eastSt = get_max_east();
  cout << "Maximum storage in East basin: " << max_eastSt << " billion gallons" << endl;
  // Output: Maximum storage in East basin: 81.07 billion gallons

  cout << endl;

  string higherBasin = compare_basins("01/01/2018");
  cout << "Higher basin: " << higherBasin << endl;
  // Output: West
  higherBasin = compare_basins("09/13/2018");
  cout << "Higher basin: " << higherBasin << endl;
  // Output: West
  higherBasin = compare_basins("09/14/2018");
  cout << "Higher basin: " << higherBasin << endl;
  // Output: West
  higherBasin = compare_basins("01/05/2018");
  cout << "Higher basin: " << higherBasin << endl;
  // Output: East

  cout << endl;

  reverse_order("05/29/2018","06/02/2018");

  cout << endl;

  // Intentional Test for Errors
  cout << get_east_storage("hi") << " billion gallons" << endl;
  // Output: Invalid Date Inputted
  higherBasin = compare_basins("hi");
  cout << "Higher basin: " << higherBasin << endl;
  // Output: Invalid Date Inputted

}
