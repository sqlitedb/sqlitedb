#pragma once

#include "nativium/core/ApplicationCore.hpp"

#include <memory>
#include <string>

namespace nativium
{
namespace core
{

class ApplicationCoreImpl : public ApplicationCore
{
public:
    ApplicationCoreImpl();
    virtual ~ApplicationCoreImpl() {}

    static std::shared_ptr<ApplicationCoreImpl> internalSharedInstance();

    std::string getVersion() override;
    std::string getEnv(const std::string &key) override;

private:
    static std::shared_ptr<ApplicationCoreImpl> instance;
};

} // namespace core
} // namespace nativium
