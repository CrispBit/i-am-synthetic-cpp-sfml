//
// Created by cilan on 1/20/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_LOCATOR_H
#define I_AM_SYNTHETIC_C_SFML_LOCATOR_H

#include "resources/LocalResources.h"
#include "resources/NullResources.h"
#include <boost/filesystem.hpp>

#include <memory>

class Locator {
public:
    static std::shared_ptr<IResources> getResource() { return service_; }

    static void provide(std::shared_ptr<IResources> service) {
        service_.reset();
        if (service == NULL) {
            service_ = std::move(nullService_);
        } else {
            service_ = std::move(service);
        }
    }

    static void provideArgs(char* arg);

    static boost::filesystem::path rootPath;
    static std::map<std::string, std::string> defaultConfig;
    Locator();

private:
    static std::shared_ptr<IResources> service_;
    static std::shared_ptr<IResources> nullService_;
};
#endif