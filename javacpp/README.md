# How to create an Android JavaCPP Project
## 1 Create a new native c++ project
## 2 Add implementation 'org.bytedeco:javacpp:1.5.9' to build.gradle(app)

```
dependencies {
    implementation 'org.bytedeco:javacpp:1.5.9'
    implementation 'androidx.appcompat:appcompat:1.6.1'
    implementation 'com.google.android.material:material:1.9.0'
    implementation 'androidx.constraintlayout:constraintlayout:2.1.4'
    testImplementation 'junit:junit:4.13.2'
    androidTestImplementation 'androidx.test.ext:junit:1.1.5'
    androidTestImplementation 'androidx.test.espresso:espresso-core:3.5.1'
}
```
## 3 copy NativeLibrary.java, NativeLibraryConfig.java from gradle-javacpp-android project
## 4 copy jnijavacpp.cpp jniNativeLibrary.cpp, NativeLibrary.h from gradle-javacpp-android
## 5 modify CMakeLists.txt, add jnijavacpp.cpp and jniNativeLibrary.cpp
```
add_library( # Sets the name of the library.
        myapplication

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp jnijavacpp.cpp jniNativeLibrary.cpp)
```
## 6, 
