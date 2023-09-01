import hilog from '@ohos.hilog';
import testNapi from 'libentry.so'

enum Gender {
  Man,
  Woman
}

@Entry
@Component
struct Index {
  @State message: string = 'Android+Djinni_JNI > AKI'

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {

            testNapi.androidJNISayHello(1)

            var djnniInterface = new testNapi.TestDjinniWrapper()
            var infoStore = new testNapi.MyRecord(1234, "djinni test \n", "djinni", Gender.Woman)
            var a: string = djnniInterface.sayHello(infoStore)
            this.message = a

          })
      }
      .width('100%')
    }
    .height('100%')
  }
}