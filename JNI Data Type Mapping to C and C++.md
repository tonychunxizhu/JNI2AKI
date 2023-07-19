## JNI Data Type Mapping to C /C++
https://www.developer.com/microsoft/c-sharp/jni-data-type-mapping-to-c-c/
### Data Type Mapping

The mapping between Java data types and data types used in native code is pretty straightforward. The naming scheme remains the same: the native data type name is preceded by the character ‘j’, followed by all lowercase data type name equivalent to Java. JNI also includes another data type named jsize, which stores the length or an array or string.

![image](https://github.com/tonychunxizhu/JNI2AKI/assets/32444753/592259d7-aae5-401f-9887-c4ffb0cb00f7)


In case of reference types, JNI defines a few of the most common references, such as string or class, and so forth. Other references are mapped to the JNI jobject. String, Class, and Throwable are just exceptional reference types that otherwise can be handled by jobject.

![image](https://github.com/tonychunxizhu/JNI2AKI/assets/32444753/b6ff474d-23fc-4b7f-8e12-f011250a41c3)


JNI uses jarray for a generic array type that represents the Java array type. Another data type, named jvalue, is nothing but a union type defined in C/C++.

### Conclusion
These are some of the primary yet very vital concepts to begin coding in JNI. Although data types of most languages are more or less similar, when it comes to mapping between two different languages, the question always arises about how they are mapped. Observe that the classic C/C++ data type naming is not followed in JNI. The representation may be the same, yet the naming scheme differs. Here, we have refreshed the concept, thus paving way for more hands on work in the next set of articles.

more detailed information is available here
https://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/types.html
