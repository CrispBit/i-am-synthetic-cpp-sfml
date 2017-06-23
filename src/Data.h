//
// Created by cilan on 3/20/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_DATA_H
#define I_AM_SYNTHETIC_C_SFML_DATA_H

#include <fstream>
#include <iostream>

class Data {
public:
    unsigned int levelid;
    char name[10];
    friend std::ofstream& operator<<(std::ofstream& save, Data& data);
    friend std::ifstream& operator>>(std::ifstream& save, Data& data);
};

#endif
