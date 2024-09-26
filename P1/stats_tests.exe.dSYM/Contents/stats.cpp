// stats.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
// Donavon Johnson

#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

vector<vector<double> > summarize(vector<double> v) {
    assert(!v.empty());
    vector<vector<double> > summ;
    sort(v);
    double vect_size = v.size();
    int count = 0;
    for (int i = 0; i < vect_size; i++) {
            vector<double> num;
        for (size_t k = i; k < vect_size; k++) {
            if (v[k] == v[i]) {
                count = count + 1; 
            }
        }
    num.push_back(v[i]);
    num.push_back(count);
    summ.push_back(num);
    count = 0;
    }
return summ;
}

int count(vector<double> v) {
    assert(!v.empty());
    return static_cast<int>(v.size());
}

double sum(vector<double> v) {
    assert(!v.empty());
    double sum = 0;
    double vect_size = v.size();

    for (int i = 0; i < vect_size; i++) {
        sum = sum + v[i];
    }
    return sum;
}

double mean(vector<double> v) {
    assert(!v.empty());
    double sum = 0;
    double vect_size = v.size();

    for (int i = 0; i < vect_size; i++) {
        sum = sum + v[i];
    }
    double solution;
    solution = sum / v.size();
    
    return solution;
}

double median(vector<double> v) {
    assert(!v.empty());
    sort(v);
    double a = 0;
    double b = 0;
    double c = 0;
    
    //even amount of numbers
    if (v.size() % 2 == 0) {
        a = v.size() / 2;
        b = (v.size() / 2) - 1;
        c = (v[a] + v[b])/2;
        return c;
    }
    //odd amount of numbers
    else {
        a = ((v.size() - 1) / 2);
        return v[a];
    }
}

double mode(vector<double> v) {
    assert(!v.empty());
    int size = (v.size());
    double answer;
    double holder = 0;
    double num = 0;
    sort(v);

    for(int k = 0; k < size; k++) {
        for(int i = k; i < size; i++) {
            if (v[k] == v[i]) {
                num = num + 1; 
            } 
            if (num > holder) {
                holder = num;
                answer = v[i];
            }
        }
                    num = 0;

    }
    return answer;
}

double min(vector<double> v) {
    assert(!v.empty());
    sort(v);
    return v[0];    
}

double max(vector<double> v) {
    assert(!v.empty()); 
    sort(v);
    double num = v.size() - 1;
    return v[num];

}

double stdev(vector<double> v) {
    assert(v.size() >= 2);
    double value = 0;
    double avg = mean(v);
    double vect_size = v.size();

    for (int i = 0; i < vect_size; i++) {
        value = value + (v[i] - avg) * (v[i] - avg);
    }
    return sqrt((value)/(v.size()-1));
}

double percentile(vector<double> v, double p) {
    assert(!v.empty());
    sort(v);

    double n = 0;
    n = p*(v.size()-1) + 1;

  double d = 0;
  double k = 0;
  //use modf to extract fractional part and integral part of pi
  d = modf(n , &k);
  double vk = v[k-1]; 
  double vk1;
  if(k == v.size()) {
      vk1 = v[k-1];
  } else {
      vk1 = v[k];
  }
  double vp = vk + d*(vk1 - vk);
  return vp;
}
