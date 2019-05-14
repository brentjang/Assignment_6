#include "FileIO.h"
#include <iostream>
#include <fstream>

using namespace std;

FileIO::FileIO()
{
    lineCount = 0;
    allLines = 0;
    fileName = "";
}

FileIO::FileIO(string name)
{
    lineCount = 0;
    allLines = 0;
    fileName = name;
    totalLines();
}

FileIO::~FileIO()
{

}

bool FileIO::isFile()
{
    ifstream file(fileName);
    if(!file.good())
    {
        cout << "Not a file." << endl;
        return false;
    }
    //check if the file is empty
    // else if(file.peek() == ifstream::traits_type::eof())
    // {
    //     cout << "File is empty." << endl;
    //     return true;
    // }
    return true;
}

//gets next int at a given line
double FileIO::getLine(int lines)
{
    if(isFile())
    {
        ifstream file(fileName);
        string line;
        int currLine = 0;
        double out;
        while(getline(file, line))
        {
            out = stod(line);
            if(currLine == lines)
            {
                break;
            }
            currLine++;
        }
        return out;
    }
}

//compute line count in a file
void FileIO::totalLines()
{
    ifstream file(fileName);
    string line;
    while(getline(file, line))
    {
        allLines++;
    }
}

int FileIO::getTotalLines()
{
    return allLines;
}

string FileIO::getFileName()
{
    return fileName;
}

void FileIO::makeRandom()
{
    if(isFile())
    {
        ofstream ofs;
        ofs.open(fileName, ofstream::out | ofstream::trunc);
        ofs.close();
        ofstream printFile(fileName, ios_base::app);
        double num = (double)rand() / RAND_MAX;
        for(int i = 0; i < 1000; i++)
        {
            printFile << num << '\n';
            num = (double)rand() / RAND_MAX;
        }
    }
    totalLines();
}
