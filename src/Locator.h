//
// Created by cilan on 1/20/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_LOCATOR_H
#define I_AM_SYNTHETIC_C_SFML_LOCATOR_H

#include "resources/LocalResources.h"
#include "resources/NullResources.h"

#include <boost/filesystem.hpp>
#include <memory>

enum class Configs {
    DEFAULT,
    CURRENT
};

class Locator {
public:
    static std::shared_ptr<IResources> getResource() { return resourcesService_; }

    static void provideResourcesService(std::shared_ptr<IResources> service);
    static void provideArgs(char* arg);
    static void provideConfig(std::string path, Configs config);

    static boost::filesystem::path rootPath;
    static YAML::Node defaultConfig;
    static YAML::Node currentConfig;
    Locator();
private:
    static std::shared_ptr<IResources> resourcesService_;
    static std::shared_ptr<IResources> nullResourcesService_;
};
#endif
