////
//// Created on 2023-08-28.
////
//// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
//// please include "napi/native_api.h".
//
//#ifndef ISayHello_hello_H
//#define ISayHello_hello_H
//
//#pragma once
//
//#include <cstdint>
//#include <memory>
//#include <string>
//#include <stdint.h>
//#include "header/MyRecord.h"
//#include "header/ISayHello.h"
//#include <bits/alltypes.h>
//#include <optional>
//#include <aki/jsbind.h>
//#include "header/Gender.h"
//
//namespace test {
//namespace hello {
//
//struct MyRecord;
//
//class ISayHello {
//public:
//    virtual ~ISayHello() {}
//
//    static constexpr int32_t VERSION = 1;
//
////    virtual std::string sayHello(const MyRecord &testInfo);
//
//    static std::shared_ptr<ISayHello> NewInstance();
//};
//
//} // namespace hello
//} // namespace test
//
//namespace djinni_generated {
//
//class JavaProxy {
//public:
//    int64_t handle;
//};
//
//class JNIISayHello {
//public:
//    using CppType = std::shared_ptr<::test::hello::ISayHello>;
//    using CppOptType = std::shared_ptr<::test::hello::ISayHello>;
//
//    using Boxed = JNIISayHello;
//
//    ~JNIISayHello();
//
//private:
//    JNIISayHello();
//};
//
//class JNIGender {
//public:
//    using CppType = ::test::hello::Gender;
//
//    using Boxed = JNIGender;
//
//    CppType toCpp(int j) { return static_cast<CppType>(j); }
//
//    int fromCpp(CppType c) { return static_cast<int>(c); }
//
//private:
//};
//
//class JNIMyRecord final {
//public:
//    using CppType = ::test::hello::MyRecord;
//    //        using JniType = jobject;
//
//    using Boxed = JNIMyRecord;
//
//    ~JNIMyRecord();
//
//private:
//    JNIMyRecord();
//};
//
//} // namespace djinni_generated
//
//#endif // ISayHello_hello_H
