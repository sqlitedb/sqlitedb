// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "nativium/data/NTVRepositoryView.hpp"  // my header

namespace djinni_generated {

auto NTVRepositoryView::toCpp(const JsType& j) -> CppType {
    return {::djinni::String::Boxed::toCpp(j["name"])};
}
auto NTVRepositoryView::fromCpp(const CppType& c) -> JsType {
    em::val js = em::val::object();
    js.set("name", ::djinni::String::Boxed::fromCpp(c.name));
    return js;
}

}  // namespace djinni_generated
