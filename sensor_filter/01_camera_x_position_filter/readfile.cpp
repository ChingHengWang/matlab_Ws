// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int status; 

using namespace std;
string sourcepath="myFilter0.txt";
string outfile1path="t.txt";
string outfile2path="raw.txt";
string outfile3path="filter.txt";
void display(vector<string> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n" << endl;
}  

 
int sw=0;

int main () {

  string line;
  vector<string> actual; actual.clear();
  vector<string> target; target.clear();
  vector<string> dT; dT.clear();

  fstream sourcefile (sourcepath.c_str());

  ofstream outfile1;
  ofstream outfile2;
  ofstream outfile3;

  outfile1.open (outfile1path.c_str(),ios::in|ios::trunc);
  outfile2.open (outfile2path.c_str(),ios::in|ios::trunc);
  outfile3.open (outfile3path.c_str(),ios::in|ios::trunc);

  if (sourcefile.is_open() && outfile1.is_open() && outfile2.is_open() && outfile3.is_open())
  {
    while ( getline (sourcefile,line) )
    {
	string tmp1,tmp2,tmp3;	
	stringstream ss(line);
	ss>>tmp1;ss>>tmp2;ss>>tmp3;
        outfile1<<tmp1<<endl;
        outfile2<<tmp2<<endl;
        outfile3<<tmp3<<endl;
	cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<endl;

    }
    sourcefile.close();
    outfile1.close();
    outfile2.close();
    outfile3.close();

  }
  else cout << "Unable to open file"; 


  return 0;
}
