// main.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5

#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>

#include <iostream>
using namespace std;

int main() {
    
    //Ask for file name
    string file_name ;
    cout << "enter a filename" << endl;
    cin >> file_name;
    
    //Ask for column
    string column_name;
    cout << "enter a column name" << endl;
    cin >> column_name;
    cout << "reading column " << column_name << " from " << file_name << endl;
    
    //Print summary
    
    
    vector<double> input = extract_column(file_name, column_name);
    vector<vector<double> > the_summary = summarize(input);
    cout << "Summary (value: frequency)" << endl;
    for (int i = 0; i < the_summary.size(); ++i) {
        double val = the_summary[i][0];
        double freq = the_summary[i][1];
        
        cout << val << ": " << freq << endl;
    }

    
    //list stats
    cout << "count = "  << count(input) << endl;
    cout << "sum = "    << sum(input) << endl;
    cout << "mean = "   << mean(input) << endl;
    cout << "stdev = "  << stdev(input) << endl;
    cout << "median = " << median(input) << endl;
    cout << "mode = "   << mode(input) << endl;
    cout << "min = "    << min(input) << endl;
    cout << "max = "    << max(input) << endl;
    cout << "  0th percentile = " << percentile(input, 0.00) << endl;
    cout << " 25th percentile = " << percentile(input, 0.25) << endl;
    cout << " 50th percentile = " << percentile(input, 0.50) << endl;
    cout << " 75th percentile = " << percentile(input, 0.75) << endl;
    cout << "100th percentile = " << percentile(input, 1.00) << endl;



    
}
