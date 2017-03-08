//
// Created by cilan on 1/20/2017.
//

#include "Locator.h"

std::shared_ptr<IResources> Locator::nullService_ = std::make_shared<NullResources>();
std::shared_ptr<IResources> Locator::service_ = std::move(Locator::nullService_);

YAML::Node Locator::defaultConfig;

boost::filesystem::path Locator::rootPath;

Locator::Locator() {
    Locator::service_.reset();
}

void Locator::provide(std::shared_ptr<IResources> service) {
    service_.reset();
    if (service == NULL) {
        service_ = std::move(nullService_);
    } else {
        service_ = std::move(service);
    }
}

void Locator::provideArgs(char arg[]) {
    Locator::rootPath = boost::filesystem::canonical(arg).remove_filename().parent_path();
    if (!rootPath.has_filename()) std::cout << "TO-DO";
}

void Locator::provideConfig(std::string path) {
    Locator::defaultConfig = YAML::LoadFile(path); // TODO: work for other config files
}
