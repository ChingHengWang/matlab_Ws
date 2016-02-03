// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "filt.h"


int status; 
//ts 0.1s

using namespace std;
void display(vector<string> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n" << endl;
}  

 
int sw=0;

int main (int argc, char** argv) {

  string sourcepath="data.txt";
  string outfile1path="raw_data.txt";
  string outfile2path="filter_data.txt";
  double shift = atof(argv[1]);
  double taps = atof(argv[2]);
  double Fs = atof(argv[3]);
  double Fx = atof(argv[4]);

  Filter *my_filter;
  my_filter = new Filter(LPF, taps, Fs, Fx);
  string line;
  vector<string> actual; actual.clear();
  vector<string> target; target.clear();
  vector<string> dT; dT.clear();
  fstream sourcefile (sourcepath.c_str());

  ofstream outfile1;
  ofstream outfile2;

  outfile1.open (outfile1path.c_str(),ios::in|ios::trunc);
  outfile2.open (outfile2path.c_str(),ios::in|ios::trunc);

  if (sourcefile.is_open() && outfile1.is_open()&& outfile1.is_open())
  {
    while ( getline (sourcefile,line) )
    {
	string txt;
	double tmp1;	
	stringstream ss(line);
	ss>>tmp1;
	
	tmp1=tmp1-shift;
	double out_val = my_filter->do_sample( (double) tmp1 );
	out_val=out_val+shift;
        outfile1<<tmp1<<endl;
        outfile2<<out_val<<endl;
	cout<<out_val<<endl;

    }
    sourcefile.close();
    outfile1.close();
    outfile2.close();

  }
  else cout << "Unable to open file"; 


  return 0;
}
