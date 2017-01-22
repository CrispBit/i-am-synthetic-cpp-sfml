//
// Created by cilan on 1/20/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_LOCATOR_H
#define I_AM_SYNTHETIC_C_SFML_LOCATOR_H

#include "LocalResources.h"
#include <memory>

class Locator {
public:
    static std::shared_ptr<IResources> getResource() { return service_; }
    static std::shared_ptr<IResources> service_;
};

#endif