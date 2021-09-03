#include <stdexcept>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream> //to use istringstream

using namespace std;


struct Student
{
  string Name;
  int age;
  double score;
  friend std::ostream &operator<<(std::ostream &os, const Student p)
  {
    os << p.Name << ", " << p.age << " years old, the score is "
       << p.score << endl;
    return os;
  }
};

void Readfile(vector<Student> &Students, string &fname)
{
  ifstream in;
  in.open(fname, ios::in);
  if (!in) { //If in is true the file exit
    throw invalid_argument("Test file doesn't exist");
  }
  // cout << fname;
  string line;
  // cout<<num_atoms;
  while (getline(in, line))
  {
    istringstream iss(line);
    Student SA;
    if (!(iss >> SA.Name >> SA.age >> SA.score))
    {
      throw invalid_argument("There is some problem with Student format.");
    }
    Students.push_back(SA);
  }
  in.close();
}


int main(int argc, char* argv[])
{
  if (argc != 2){
    cout << "Please input the file name!";
  }
  vector<Student> Students;
  string fname = argv[1];
  try
  {
    Readfile(Students, fname);
  }
  catch (invalid_argument &e)
  {
    cerr << e.what() << endl;
    return EXIT_FAILURE;
  }

  for (auto x : Students)
    cout << x ;

  return EXIT_SUCCESS;
}
