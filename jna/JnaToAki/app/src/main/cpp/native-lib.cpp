#include <cstring>
#include <iostream>
#include <android/log.h>

#define TAG "Jacky"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__);

struct MyStructure {
    int a;
    int b;
};

extern "C" int add(MyStructure* s) {
    return s->a + s->b;
}

typedef char* (*Callback2)(char*, int);

extern "C" void changeName(char* str) {
    const char* newName = "aaa";
    strcpy(str, newName);
}

extern "C" char* changeName2() {
    char* newName = new char[4];
    strcpy(newName, "aaa");
    return newName;
}

extern "C" void changeNum(int* num) {
    (*num) += 10;
}

extern "C" double changeDouble() {
    return 60.00;
}

extern "C" int add1(int a, int b) {
    return a + b;
}

extern "C" int calculateArea(int length, int width) {
    return length * width;
}
extern "C" int calculatePerimeter(int length, int width) {
    return 2 * (length + width);

}

typedef int (*Callback)(int, int);
extern "C" void addN(Callback callback) {
    int i = callback(2, 3);
    LOGD("add number: %d", i);
}

extern "C" void show(Callback2 callback) {
    char* newName = new char[4];
    strcpy(newName, "pm");
    newName = callback(newName, 4);
    LOGD("current time: %s", newName);
}