//
// Created by cilan on 3/20/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_DATA_H
#define I_AM_SYNTHETIC_C_SFML_DATA_H

#include <fstream>
#include <iostream>

class Data {
public:
    int levelid;
    std::ostream& operator<<(std::ofstream& save);
    std::istream& operator>>(std::ifstream& save);
};

#endif //I_AM_SYNTHETIC_C_SFML_DATA_H
