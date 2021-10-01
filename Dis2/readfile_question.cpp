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

void Readfile(vector<double> &Readed, string &fname)
{
    ifstream in;
    in.open(fname, ios::in); //ifstream in(fname, ios::in);
    // in >> Readed;
    string line;
    double readed_double;
    while(getline(in, line))
    {
        istringstream iss(line);
        iss >> readed_double;
        Readed.push_back(readed_double);
    }
    in.close();
}

void Readfile(vector<Student> &Readed, string &fname)
{
    ifstream in;
    in.open(fname, ios::in); //ifstream in(fname, ios::in);
    // in >> Readed;
    string line;
    Student readed_stu;
    while(getline(in, line))
    {
        istringstream iss(line);
        iss >> readed_stu.Name >> readed_stu.age >> readed_stu.score;
        Readed.push_back(readed_stu);
    }
    in.close();
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Please input the file name!";
    }
    vector<Student> Readed;
    string fname = argv[1];
    Readfile(Readed, fname);

    // cout << "We read " << Readed << " from the file." << endl;
    for(auto x:Readed)
        cout<<x <<endl;
    return EXIT_SUCCESS;
}
