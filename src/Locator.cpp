//
// Created by cilan on 1/20/2017.
//

#include "Locator.h"

std::shared_ptr<IWindowSubroutines> Locator::nullResourcesService_ = std::make_shared<NullWindowSubroutines>();
std::shared_ptr<IWindowSubroutines> Locator::resourcesService_ = Locator::nullResourcesService_;

std::shared_ptr<IWindowSubroutines> Locator::nullWindowRoutinesService_ = std::make_shared<NullWindowSubroutines>();
std::shared_ptr<IWindowSubroutines> Locator::windowRoutinesService_ = Locator::nullWindowRoutinesService_;

YAML::Node Locator::defaultConfig;

boost::filesystem::path Locator::rootPath;

Locator::Locator() {
    Locator::resourcesService_.reset();
    Locator::windowRoutinesService_.reset();
}

void Locator::provideResourcesService(std::shared_ptr<IWindowSubroutines> service) {
    resourcesService_.reset();
    if (service == NULL) {
        resourcesService_ = nullResourcesService_;
    } else {
        resourcesService_ = std::move(service);
    }
}

void Locator::provideWindowSubroutinesService(std::shared_ptr<IWindowSubroutines> service) {
    windowRoutinesService_.reset();
    if (service == NULL) {
        windowRoutinesService_ = nullWindowRoutinesService_;
    } else {
        windowRoutinesService_ = std::move(service);
    }
}

void Locator::provideArgs(char arg[]) {
    Locator::rootPath = boost::filesystem::canonical(arg).remove_filename().parent_path();
    if (!rootPath.has_filename()) std::cout << "TO-DO";
}

void Locator::provideConfig(std::string path) {
    Locator::defaultConfig = YAML::LoadFile(path); // TODO: work for other config files
}
