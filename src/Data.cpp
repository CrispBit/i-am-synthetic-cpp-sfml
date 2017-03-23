//
// Created by cilan on 3/20/2017.
//

#include "Data.h"

std::ostream& Data::operator<<(std::ofstream& save) {
    std::cout << "lol" << std::endl;
    return save;
}

std::istream& Data::operator>>(std::ifstream& save) {
    return save;
}
