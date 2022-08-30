// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "com/nativium/data/NTVRepositoryRow.hpp"  // my header
#include "djinni/jni/Marshal.hpp"

namespace djinni_generated {

NTVRepositoryRow::NTVRepositoryRow() = default;

NTVRepositoryRow::~NTVRepositoryRow() = default;

auto NTVRepositoryRow::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NTVRepositoryRow>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::List<::djinni::String>::fromCpp(jniEnv, c.values)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NTVRepositoryRow::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 2);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NTVRepositoryRow>::get();
    return {::djinni::List<::djinni::String>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mValues))};
}

}  // namespace djinni_generated
