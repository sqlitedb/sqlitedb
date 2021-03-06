// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "com/nativium/data/NTVRepositoryInfo.hpp"  // my header
#include "com/nativium/data/NTVDatabaseFileData.hpp"
#include "com/nativium/data/NTVRepositoryTable.hpp"
#include "com/nativium/data/NTVRepositoryView.hpp"
#include "djinni/jni/Marshal.hpp"

namespace djinni_generated {

NTVRepositoryInfo::NTVRepositoryInfo() = default;

NTVRepositoryInfo::~NTVRepositoryInfo() = default;

auto NTVRepositoryInfo::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NTVRepositoryInfo>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.sqliteVersion)),
                                                           ::djinni::get(::djinni_generated::NTVDatabaseFileData::fromCpp(jniEnv, c.fileData)),
                                                           ::djinni::get(::djinni::List<::djinni_generated::NTVRepositoryTable>::fromCpp(jniEnv, c.tables)),
                                                           ::djinni::get(::djinni::List<::djinni_generated::NTVRepositoryView>::fromCpp(jniEnv, c.views)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NTVRepositoryInfo::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 5);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NTVRepositoryInfo>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mSqliteVersion)),
            ::djinni_generated::NTVDatabaseFileData::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mFileData)),
            ::djinni::List<::djinni_generated::NTVRepositoryTable>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mTables)),
            ::djinni::List<::djinni_generated::NTVRepositoryView>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mViews))};
}

}  // namespace djinni_generated
