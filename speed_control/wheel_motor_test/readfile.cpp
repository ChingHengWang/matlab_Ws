// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


void display(vector<string> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n" << endl;
}  

 


int main () {

  string line;
  vector<string> actual; actual.clear();
  vector<string> target; target.clear();
  vector<string> dT; dT.clear();
  fstream myfile ("test.txt");
  ofstream outfile1;
  ofstream outfile2;
  ofstream outfile3;

  outfile1.open ("acutal.txt",ios::in|ios::trunc);
  outfile2.open ("target.txt",ios::in|ios::trunc);
  outfile3.open ("dT.txt",ios::in|ios::trunc);

  if (myfile.is_open() && outfile1.is_open() && outfile2.is_open() && outfile3.is_open())
  {
    while ( getline (myfile,line) )
    {
      stringstream ss(line);
      //size_t found=line.find("actual");
      string tmpStr1,tmpStr2,tmpStr3;
      ss>>tmpStr1; outfile1<<tmpStr1<<endl;
      //actual.push_back(tmpStr);      
      ss>>tmpStr2; outfile2<<tmpStr2<<endl;
      //target.push_back(tmpStr);      
      ss>>tmpStr3; outfile3<<tmpStr3<<endl;
      //dT.push_back(tmpStr);      

    }
    myfile.close();
    outfile1.close();
    outfile2.close();
    outfile3.close();

  }
  else cout << "Unable to open file"; 

//  display(actual);display(target);display(dT);

/*

  if (outfile1.is_open() && outfile2.is_open() && outfile3.is_open())
  {


    outfile1<<"hello"<<endl;


    outfile1.close();
    outfile2.close();
  }
  else cout << "Unable to open file"; 

*/

  return 0;
}
