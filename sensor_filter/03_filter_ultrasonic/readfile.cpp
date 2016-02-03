// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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

string sourcepath=argv[1];
string outfile1path="data.txt";

  string line;
  vector<string> actual; actual.clear();
  vector<string> target; target.clear();
  vector<string> dT; dT.clear();

  fstream sourcefile (sourcepath.c_str());

  ofstream outfile1;

  outfile1.open (outfile1path.c_str(),ios::in|ios::trunc);

  if (sourcefile.is_open() && outfile1.is_open())
  {
    while ( getline (sourcefile,line) )
    {
	string tmp1,tmp2,tmp3,txt;	
	stringstream ss(line);
	ss>>txt;ss>>tmp1;
        outfile1<<tmp1<<endl;
	getline (sourcefile,line);
	cout<<tmp1<<endl;

    }
    sourcefile.close();
    outfile1.close();

  }
  else cout << "Unable to open file"; 


  return 0;
}
