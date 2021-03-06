// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/jni/djinni_support.hpp"
#include "nativium/data/RepositoryRow.hpp"

namespace djinni_generated {

class NTVRepositoryRow final {
public:
    using CppType = ::nativium::data::RepositoryRow;
    using JniType = jobject;

    using Boxed = NTVRepositoryRow;

    ~NTVRepositoryRow();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NTVRepositoryRow();
    friend ::djinni::JniClass<NTVRepositoryRow>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nativium/data/RepositoryRow") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/util/ArrayList;)V") };
    const jfieldID field_mValues { ::djinni::jniGetFieldID(clazz.get(), "mValues", "Ljava/util/ArrayList;") };
};

}  // namespace djinni_generated
