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

 
int sw=0;

int main () {

  string line;
  vector<string> actual; actual.clear();
  vector<string> target; target.clear();
  vector<string> dT; dT.clear();
  fstream myfile ("test3.txt");
  ofstream outfile1;
  ofstream outfile2;

  outfile1.open ("Z.txt",ios::in|ios::trunc);
  outfile2.open ("Z_K.txt",ios::in|ios::trunc);

  if (myfile.is_open() && outfile1.is_open() && outfile2.is_open())
  {
    while ( getline (myfile,line) )
    {
	
      if(line.compare(" ")<0)
	;
      else{

 
      if (line.compare("Z_K")==1)
  	{sw=1;getline (myfile,line);}
      else if (line.compare("Z")==1)
  	{sw=2;getline (myfile,line);}
      stringstream ss(line);

      switch(sw){
  	case 1:
	  outfile2<<ss.str()<<endl;
	break;	
	case 2:
	  outfile1<<ss.str()<<endl;
	break;	

      }
     }
/*
      stringstream ss(line);
      //size_t found=line.find("actual");
      string tmpStr1,tmpStr2,tmpStr3;
      ss>>tmpStr1; outfile1<<tmpStr1<<endl;
      //actual.push_back(tmpStr);      
      ss>>tmpStr2; outfile2<<tmpStr2<<endl;
      //target.push_back(tmpStr);      
*/
    }
    myfile.close();
    outfile1.close();
    outfile2.close();

  }
  else cout << "Unable to open file"; 


  return 0;
}
