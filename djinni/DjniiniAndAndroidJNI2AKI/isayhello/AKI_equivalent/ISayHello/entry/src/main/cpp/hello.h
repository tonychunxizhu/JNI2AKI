////
//// Created on 2023-08-28.
////
//// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
//// please include "napi/native_api.h".
//
//#ifndef ISayHello_hello_H
//#define ISayHello_hello_H
//
//#include <bits/alltypes.h>
//#include <cstdint>
//#include <string>
//#include <memory>
//#include <utility>
//#include "aki/jsbind.h"
//
//namespace test {
//namespace hello {
//
//enum class Gender {
//    Man,
//    Woman,
//};
//
//struct MyRecord final {
//    int32_t id;
//    std::string name;
//    std::string project;
//    Gender sex;
//
//    MyRecord(int32_t id_, std::string name_, std::string project_, Gender sex_)
//        : id(std::move(id_)), name(std::move(name_)), project(std::move(project_)), sex(std::move(sex_)) {}
//};
//
//class ISayHello
//{
//public:
//    //    virtual ~ISayHello() {}
//
//    static constexpr int32_t VERSION = 1;
//
//    //    std::string sayHello(const MyRecord &testInfo);
//
//    static std::shared_ptr<ISayHello> NewInstance();
//};
//
//JSBIND_CLASS(MyRecord) {
//    //    JSBIND_CONSTRUCTOR<>();
//    //    JSBIND_METHOD(sayHello);
//    JSBIND_PROPERTY(id);
//    JSBIND_PROPERTY(name);
//    JSBIND_PROPERTY(project);
//    JSBIND_PROPERTY(sex);
//}
//
////JSBIND_ENUM(Gender) {
////    JSBIND_ENUM_VALUE(Man);
////    JSBIND_ENUM_VALUE(Woman);
////}
//
//} // namespace hello
//} // namespace test
//
//#endif // ISayHello_hello_H
