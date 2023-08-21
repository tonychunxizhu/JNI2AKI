#include <jni.h>
#include <string>
#include "android/log.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_ruturaj_huawei_isayhello_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ruturaj_huawei_isayhello_MainActivity_androidJNISayHello(JNIEnv *env, jclass clazz,
                                                                  jint i) {
    // TODO: implement androidJNISayHello()
    __android_log_print(ANDROID_LOG_ERROR, "RRR", "%d", i);
}