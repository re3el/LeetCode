#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    // write to a file
    ofstream oFile;
    oFile.open("newFile.txt");
    oFile<<"This is the first Line"<<endl<<"This is the second line";
    oFile.close();

    // read from a file completely
    ifstream iFile;
    iFile.open("newFile.txt");
    stringstream buff;
    buff<<iFile.rdbuf();
    cout<<buff.str()<<endl;

    // read from string delimited by spaces
    string str = "     hello       can    you hear me ?   ";
    stringstream checker(str);
    string word;
    while(checker >> word)
        cout<<word<<endl;
    return 0;
}
