//
// Created by Ruturaj on 2023-08-21.
//

#ifndef SAYHELLOWORLD_IMPLEMENTATIONISAYHELLO_H
#define SAYHELLOWORLD_IMPLEMENTATIONISAYHELLO_H

#include "TestISayHello.h"
#include <cstdint>
#include <memory>
#include <string>

class ImplementationISayHello : public TEST::TestISayHello {

private:
    int64_t lis;
    bool li;
    std::string frm, t;

public:

    // Constructor
    ImplementationISayHello();

    // Our method that returns a string

    void addSayHelloListener(int64_t listener);

    void removeSayHelloListener(bool listener);

    void sayHello(const std::string &from, const std::string &to);

//    static std::shared_ptr<TestISayHello> NewInstance();

    std::string get_hello_world();
};

#endif //SAYHELLOWORLD_IMPLEMENTATIONISAYHELLO_H
