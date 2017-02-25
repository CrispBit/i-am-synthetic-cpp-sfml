//
// Created by cilan on 2/25/2017.
//

#include <string>

#ifndef I_AM_SYNTHETIC_C_SFML_BUTTON_H
#define I_AM_SYNTHETIC_C_SFML_BUTTON_H

class Button {
public:
    void setLabel(std::string);
    Button(std::string);
private:
    std::string label;
};


#endif
