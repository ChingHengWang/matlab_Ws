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
  fstream myfile ("test.txt");
  ofstream outfile1;
  ofstream outfile2;

  outfile1.open ("speed.txt",ios::in|ios::trunc);
  outfile2.open ("enc.txt",ios::in|ios::trunc);

  if (myfile.is_open() && outfile1.is_open() && outfile2.is_open())
  {
    while ( getline (myfile,line) )
    {
      stringstream ss(line);
      //size_t found=line.find("actual");
      string tmpStr1,tmpStr2;
      ss>>tmpStr1; outfile1<<tmpStr1<<endl;
      //actual.push_back(tmpStr);      
      ss>>tmpStr2; outfile2<<tmpStr2<<endl;
      //target.push_back(tmpStr);      
    }
    myfile.close();
    outfile1.close();
    outfile2.close();

  }
  else cout << "Unable to open file"; 

  return 0;
}
