//
// Created by noa on 07/12/17.
//

#ifndef EX4_FILEREADER_H
#define EX4_FILEREADER_H

#include <iostream>
using namespace std;

class FileReader {
public:
    FileReader(char *fileName);
    char *getIP();
    int getPort();
private:
    char IP [100];
    int port;
};


#endif //EX4_FILEREADER_H
