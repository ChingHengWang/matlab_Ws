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
  fstream myfile ("record.txt");
  ofstream outfile1;
  ofstream outfile2;
  ofstream outfile3;

  outfile1.open ("sin_frequency_input.txt",ios::in|ios::trunc);
  outfile2.open ("pwm_input.txt",ios::in|ios::trunc);
  outfile3.open ("angular_speed_output.txt",ios::in|ios::trunc);

  if (myfile.is_open() && outfile1.is_open() && outfile2.is_open())
  {
    while ( getline (myfile,line) )
    {
	string tmp1,tmp2,tmp3;	
	stringstream ss(line);
	ss>>tmp1;ss>>tmp2;ss>>tmp3;
        outfile1<<tmp1<<endl;
        outfile2<<tmp2<<endl;
        outfile3<<tmp3<<endl;



/*
	string tmp1,tmp2;	
	stringstream ss(line);
	getline(ss,tmp1,':');
	ss>>tmp1;
        outfile1<<tmp1<<endl;
	//cout<<tmp<<endl;
	getline(ss,tmp2,':');
	ss>>tmp2;
        outfile2<<tmp2<<endl;
	//cout<<tmp2<<endl;
*/
/* 
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
    outfile3.close();

  }
  else cout << "Unable to open file"; 


  return 0;
}
