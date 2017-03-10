//
// Created by cilan on 3/9/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_LOCALRESOURCES_H
#define I_AM_SYNTHETIC_C_SFML_LOCALRESOURCES_H

#include "IWindowSubroutines.h"
#include "../Locator.h"

class LocalResources : public IResources {
public:
    virtual void handleExits(sf::RenderWindow& window) override;
};
#endif
