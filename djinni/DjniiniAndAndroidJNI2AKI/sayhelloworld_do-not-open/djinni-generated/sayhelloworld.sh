JAVA_OUTPUT_FOLDER=target/sayhelloworld/java
CPP_OUTPUT_FOLDER=target/sayhelloworld/cpp
JNI_OUTPUT_FOLDER=target/sayhelloworld/jni
OBJC_OUTPUT_FOLDER=target/sayhelloworld/oc
NODE_OUTPUT_FOLDER=target/sayhelloworld/node
MY_PROJECT=target/sayhelloworld/say_hello_world.djinni


src/run \
--cpp-header-out $CPP_OUTPUT_FOLDER \
--cpp-optional-header absl/types/optional.h \
--cpp-optional-template absl:optional \
\
--node-out $NODE_OUTPUT_FOLDER \
--node-package QQNT \
--node-type-prefix Node \
--node-include-cpp $CPP_OUTPUT_FOLDER \
\
--java-out $JAVA_OUTPUT_FOLDER \
--java-package com.ruturaj.huawei.sayhelloworld \
\
--jni-out $JNI_OUTPUT_FOLDER \
\
--cpp-out $CPP_OUTPUT_FOLDER \
--cpp-namespace TEST \
\
--idl $MY_PROJECT
