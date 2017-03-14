//
// Created by cilan on 1/22/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_NULLWINDOWSUBROUTINES_H
#define I_AM_SYNTHETIC_C_SFML_NULLWINDOWSUBROUTINES_H

#include <iostream>
#include "IWindowSubroutines.h"

class NullWindowSubroutines : public IWindowSubroutines {
public:
    virtual void handleExits(sf::RenderWindow& window) override;
};

#endif
