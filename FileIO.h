#include <iostream>
using namespace std;

class FileIO
{
public:
    FileIO();
    FileIO(string name);
    ~FileIO();
    bool isFile();
    double getLine(int line);
    void totalLines();
    int getTotalLines();
    string getFileName();
    void makeRandom();

private:
    int lineCount;
    int allLines;
    string fileName;
};
