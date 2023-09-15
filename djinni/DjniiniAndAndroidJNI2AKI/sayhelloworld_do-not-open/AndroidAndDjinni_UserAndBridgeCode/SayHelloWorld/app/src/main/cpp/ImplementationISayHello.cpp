//
// Created by Ruturaj on 2023-08-18.
//

#include "TestISayHello.h"

#include<cstring>
#include "ISayHello.hpp"
#include "android/log.h"
#include "ImplementationISayHello.h"

#include <cinttypes>

//class ImplementationISayHello : public ::test::hello::TestISayHello {
//
//void addSayHelloListener(int64_t listener) {
//    __android_log_print(ANDROID_LOG_ERROR, "RRR: ", "%" PRId64, listener);
//}
//
//void removeSayHelloListener(bool listener) {
//    __android_log_print(ANDROID_LOG_ERROR, "RRR: ", "%s",
//                        reinterpret_cast<const char *>(listener));
//}
//
//void sayHello(const std::string &from, const std::string &to) {
//    __android_log_print(ANDROID_LOG_ERROR, "RRR: ", "%s", (from + " " + to).c_str());
//}
//
//};

ImplementationISayHello::ImplementationISayHello() : lis(1000000L), li(true),
                                                     frm(std::string("h")), t(std::string("w")) {

}

std::shared_ptr<ImplementationISayHello::TestISayHello>
ImplementationISayHello::TestISayHello::newInstance() {
    __android_log_print(ANDROID_LOG_ERROR, "RRR: ", "%s", "NewInstance Implementation 1");
    return std::make_shared<ImplementationISayHello>();
}

std::string ImplementationISayHello::get_hello_world() {

    std::string myString = "Success";

    addSayHelloListener(lis);
    removeSayHelloListener(li);
    sayHello(frm, t);

    return myString;

}

void ImplementationISayHello::addSayHelloListener(int64_t listener) {
//    listener = lis;
    __android_log_print(ANDROID_LOG_ERROR, "RRR: ", "%" PRId64, listener);
}

void ImplementationISayHello::removeSayHelloListener(bool listener) {
//    listener = li;
    __android_log_print(ANDROID_LOG_ERROR, "RRR: ", "%s",
                        reinterpret_cast<const char *>(listener));
}

void ImplementationISayHello::sayHello(const std::string &from, const std::string &to) {
//    std::string newFrom = frm;
//    std::string newTo = t;
    __android_log_print(ANDROID_LOG_ERROR, "RRR: ", "%s", (from + " " + to).c_str());
//    __android_log_print(ANDROID_LOG_ERROR, "RRR: ", "%s", (newFrom + " " + newTo).c_str());
}
