//
// Created by noa on 07/12/17.
//

#ifndef EX4_FILEREADER_H
#define EX4_FILEREADER_H

#include <iostream>
using namespace std;
#define IP_SIZE 100

class FileReader {
public:
    /**
     * Constructor.
     * @param fileName
     */
    FileReader(char *fileName);
    /**
     *
     * @return the server IP.
     */
    char *getIP();
    /**
     *
     * @return The server port.
     */
    int getPort();
private:
    char IP [IP_SIZE];
    int port;
};


#endif //EX4_FILEREADER_H
