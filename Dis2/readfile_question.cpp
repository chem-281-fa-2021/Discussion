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

void Readfile(double &Readed, string &fname)
{
    ifstream in;
    in.open(fname, ios::in);
    in >> Readed;
    // {
    //     string line;
    //     getline(in, line);
    //     istringstream iss(line);
    //     iss >> Readed;
    // }
    in.close();
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Please input the file name!";
    }
    double Readed;
    string fname = argv[1];
    Readfile(Readed, fname);

    cout << "We read " << Readed << " from the file." << endl;
    return EXIT_SUCCESS;
}
