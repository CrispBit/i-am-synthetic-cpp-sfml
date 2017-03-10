//
// Created by cilan on 1/20/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_LOCATOR_H
#define I_AM_SYNTHETIC_C_SFML_LOCATOR_H

#include "resources/LocalResources.h"
#include "resources/NullResources.h"

#include "window-subroutines/InfoWindowSubroutines.h"
#include "window-subroutines/NullWindowSubroutines.h"

#include <boost/filesystem.hpp>
#include <memory>

class Locator {
public:
    static std::shared_ptr<IWindowSubroutines> getResource() { return resourcesService_; }

    static void provideResourcesService(std::shared_ptr<IWindowSubroutines> service);
    static void provideWindowSubroutinesService(std::shared_ptr<IWindowSubroutines> service);
    static void provideArgs(char* arg);
    static void provideConfig(std::string path);

    static boost::filesystem::path rootPath;
    static YAML::Node defaultConfig;
    Locator();

private:
    static std::shared_ptr<IWindowSubroutines> resourcesService_;
    static std::shared_ptr<IWindowSubroutines> nullResourcesService_;

    static std::shared_ptr<IWindowSubroutines> windowRoutinesService_;
    static std::shared_ptr<IWindowSubroutines> nullWindowRoutinesService_;
};
#endif