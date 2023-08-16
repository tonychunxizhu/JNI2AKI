#include <jni.h>
#include <string>
#include <android/log.h>
#include "ISayHello.hpp"

extern "C" JNIEXPORT jstring
Java_com_ruturaj_huawei_sayhelloworld_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Android+Djinni JNI > AKI";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_ruturaj_huawei_sayhelloworld_MainActivity_sayHello(JNIEnv *env, jclass clazz, jint i) {
    // TODO: implement sayHello()

    __android_log_print(ANDROID_LOG_DEBUG, "RRR", "sayHello Method");

    __android_log_print(ANDROID_LOG_DEBUG, "RRR", "%d", i);

    return i;
}

/*
ISayHello_::~ISayHello_() = default;

ISayHello_::ISayHello_() = default;

////std::string toCpp(JNIEnv *pEnv, jstring pJstring);
//
// std::string toCpp(JNIEnv *pEnv, jstring pJstring) {
//    return ISayHello_::toCpp(*pEnv, pJstring);
//}

CJNIEXPORT void JNICALL Java_com_example_jnigenpackage_ISayHello_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject */
/*this*//*
, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::JavaProxyHandle<::ISayHello_>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_example_jnigenpackage_ISayHello_00024CppProxy_native_1addSayHelloListener(JNIEnv* jniEnv, jobject */
/*this*//*
, jlong nativeRef, jlong j_listener)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::objectFromHandleAddress<::ISayHello_>(nativeRef);
        ref->addSayHelloListener(ISayHello_::toCpp(jniEnv, j_listener));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_example_jnigenpackage_ISayHello_00024CppProxy_native_1removeSayHelloListener(JNIEnv* jniEnv, jobject */
/*this*//*
, jlong nativeRef, jboolean j_listener)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::objectFromHandleAddress<::ISayHello_>(nativeRef);
        ref->removeSayHelloListener(ISayHello_::toCpp(jniEnv, j_listener));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_example_jnigenpackage_ISayHello_00024CppProxy_native_1sayHello(JNIEnv* jniEnv, jobject */
/*this*//*
, jlong nativeRef, jstring j_from, jstring j_to)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::objectFromHandleAddress<::ISayHello_>(nativeRef);

        std::string from = ISayHello_::toCpp(jniEnv, j_from);
        std::string to = ISayHello_::toCpp(jniEnv, j_to);

        ref->sayHello(from, to);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}*/