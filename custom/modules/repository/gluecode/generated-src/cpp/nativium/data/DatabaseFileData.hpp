// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include <cstdint>
#include <string>
#include <utility>

namespace nativium { namespace data {

struct DatabaseFileData final {
    std::string name;
    int64_t fileSize;
    std::string filePath;

    DatabaseFileData(std::string name_,
                     int64_t fileSize_,
                     std::string filePath_)
    : name(std::move(name_))
    , fileSize(std::move(fileSize_))
    , filePath(std::move(filePath_))
    {}
};

} }  // namespace nativium::data
