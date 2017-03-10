//
// Created by cilan on 1/22/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_NULLRESOURCES_H
#define I_AM_SYNTHETIC_C_SFML_NULLRESOURCES_H

#include <iostream>
#include "IWindowSubroutines.h"

class NullResources : public IResources {
public:
    virtual void handleExits() override;
};
#endif
