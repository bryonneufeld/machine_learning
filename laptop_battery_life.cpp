//Machine Learning Problem from:
//https://www.hackerrank.com/challenges/battery/problem
//
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

//will be our global fitting parameters:
//tw = if(a*t < b, a*tc, b)
double a, b;

//read in the training data:
void training()
{
    ifstream infile;
    infile.open("laptop_input.txt");

    vector <double> watch; vector <double> charge;

    //will indicate max battery life
    double max_watch = 0;
    //will indicate time to full charge
    double full_charge_time = 0;

    string str_in; stringstream os;
    while(getline(infile,str_in))
    {
        double time_ch, time_watch;
        string str2, str3;

        os << str_in;

        getline(os,str2,',');
        time_ch = atof(str2.c_str());

        getline(os,str3);
        time_watch = atof(str3.c_str());
        os.clear();

        if(time_watch > max_watch)
        {
            max_watch = time_watch;
        }

        if(time_ch > full_charge_time)
        {
            full_charge_time = time_ch;
        }

        watch.push_back(time_watch); charge.push_back(time_ch);

    }

    infile.close();

    b = max_watch;

    a = 0; int cnt = 0;
    for(int i = 0; i < charge.size(); i++)
    {
        if(watch[i] < max_watch && watch[i] > 0.0)
        {
            a = a + watch[i]/charge[i];
            cnt++;
        }
    }
    a = a/cnt;
}


int main()
{
    training();

    double timeCharged;
    cin >> timeCharged;

    double timeWatched = min(b,a*timeCharged);
    if(timeWatched < 0){timeWatched = 0;}

    cout << timeWatched << endl;

    return 0;
}










