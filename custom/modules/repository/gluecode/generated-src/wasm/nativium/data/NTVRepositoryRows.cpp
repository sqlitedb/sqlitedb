// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "nativium/data/NTVRepositoryRows.hpp"  // my header
#include "nativium/data/NTVRepositoryRow.hpp"

namespace djinni_generated {

auto NTVRepositoryRows::toCpp(const JsType& j) -> CppType {
    return {::djinni::List<::djinni_generated::NTVRepositoryRow>::Boxed::toCpp(j["list"]),
            ::djinni::I32::Boxed::toCpp(j["amount"])};
}
auto NTVRepositoryRows::fromCpp(const CppType& c) -> JsType {
    em::val js = em::val::object();
    js.set("list", ::djinni::List<::djinni_generated::NTVRepositoryRow>::Boxed::fromCpp(c.list));
    js.set("amount", ::djinni::I32::Boxed::fromCpp(c.amount));
    return js;
}

}  // namespace djinni_generated
