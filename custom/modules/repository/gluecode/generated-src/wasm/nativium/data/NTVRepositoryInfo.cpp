// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "nativium/data/NTVRepositoryInfo.hpp"  // my header
#include "nativium/data/NTVDatabaseFileData.hpp"
#include "nativium/data/NTVRepositoryTable.hpp"
#include "nativium/data/NTVRepositoryView.hpp"

namespace djinni_generated {

auto NTVRepositoryInfo::toCpp(const JsType& j) -> CppType {
    return {::djinni::String::Boxed::toCpp(j["sqliteVersion"]),
            ::djinni_generated::NTVDatabaseFileData::Boxed::toCpp(j["fileData"]),
            ::djinni::List<::djinni_generated::NTVRepositoryTable>::Boxed::toCpp(j["tables"]),
            ::djinni::List<::djinni_generated::NTVRepositoryView>::Boxed::toCpp(j["views"])};
}
auto NTVRepositoryInfo::fromCpp(const CppType& c) -> JsType {
    em::val js = em::val::object();
    js.set("sqliteVersion", ::djinni::String::Boxed::fromCpp(c.sqliteVersion));
    js.set("fileData", ::djinni_generated::NTVDatabaseFileData::Boxed::fromCpp(c.fileData));
    js.set("tables", ::djinni::List<::djinni_generated::NTVRepositoryTable>::Boxed::fromCpp(c.tables));
    js.set("views", ::djinni::List<::djinni_generated::NTVRepositoryView>::Boxed::fromCpp(c.views));
    return js;
}

}  // namespace djinni_generated
