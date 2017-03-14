//
// Created by cilan on 3/9/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_INFOWINDOWSUBROUTINES_H
#define I_AM_SYNTHETIC_C_SFML_INFOWINDOWSUBROUTINES_H

#include "IWindowSubroutines.h"
#include "../Locator.h"

class InfoWindowSubroutines : public IWindowSubroutines {
public:
    virtual void handleExits(sf::RenderWindow& window) override;
};
#endif
