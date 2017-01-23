//
// Created by cilan on 1/20/2017.
//

#include "Locator.h"

std::shared_ptr<NullResources> Locator::nullService_ = std::make_shared<NullResources>();
std::shared_ptr<IResources> Locator::service_ = std::move(Locator::nullService_);

Locator::Locator() {
    Locator::service_.reset();
}