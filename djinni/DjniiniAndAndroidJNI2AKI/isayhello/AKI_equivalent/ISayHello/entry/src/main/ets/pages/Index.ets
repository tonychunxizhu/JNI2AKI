import hilog from '@ohos.hilog';
import testNapi from 'libentry.so'
import testNapi2 from 'libentry2.so'

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

            var djnniInterface = new testNapi2.TestDjinniWrapper()
            var infoStore = new testNapi2.MyRecord(1234, "djinni test \n", "djinni", Gender.Woman)
            var a: string = djnniInterface.sayHello(infoStore)
            this.message = a

          })
      }
      .width('100%')
    }
    .height('100%')
  }
}