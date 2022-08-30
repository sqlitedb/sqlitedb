#include "ApplicationCoreImpl.hpp"

#include <memory>
#include <string>

namespace nativium
{
namespace core
{

std::shared_ptr<ApplicationCoreImpl> ApplicationCoreImpl::instance = nullptr;

ApplicationCoreImpl::ApplicationCoreImpl()
{
    // ignore
}

std::shared_ptr<ApplicationCore> ApplicationCore::shared()
{
    return ApplicationCoreImpl::internalSharedInstance();
}

std::shared_ptr<ApplicationCoreImpl> ApplicationCoreImpl::internalSharedInstance()
{
    if (instance == nullptr)
    {
        instance = std::make_shared<ApplicationCoreImpl>();
    }

    return instance;
}

std::string ApplicationCoreImpl::getVersion()
{
#ifdef NATIVIUM_CONFIG_VERSION
#define NATIVIUM_CONFIG_VERSION_STR NATIVIUM_CONFIG_VERSION
#else
#define NATIVIUM_CONFIG_VERSION_STR "1.0.0"
#endif

#ifdef NATIVIUM_CONFIG_VERSION_CODE
#define NATIVIUM_CONFIG_VERSION_CODE_STR NATIVIUM_CONFIG_VERSION_CODE
#else
#define NATIVIUM_CONFIG_VERSION_CODE_STR "1"
#endif

    return std::string(NATIVIUM_CONFIG_VERSION_STR) + " (" + std::string(NATIVIUM_CONFIG_VERSION_CODE_STR) + ")";
}

std::string ApplicationCoreImpl::getEnv(const std::string &key)
{
    char const *val = getenv(key.c_str());
    return val == nullptr ? std::string() : std::string(val);
}

} // namespace core
} // namespace nativium
