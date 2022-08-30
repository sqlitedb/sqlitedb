// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include <cstdint>
#include <string>
#include <utility>

namespace nativium { namespace data {

struct RepositoryColumn final {
    int64_t id;
    std::string name;
    std::string type;
    bool notNull;
    std::string defaultValue;
    bool pk;
    std::string groupType;

    RepositoryColumn(int64_t id_,
                     std::string name_,
                     std::string type_,
                     bool notNull_,
                     std::string defaultValue_,
                     bool pk_,
                     std::string groupType_)
    : id(std::move(id_))
    , name(std::move(name_))
    , type(std::move(type_))
    , notNull(std::move(notNull_))
    , defaultValue(std::move(defaultValue_))
    , pk(std::move(pk_))
    , groupType(std::move(groupType_))
    {}
};

} }  // namespace nativium::data