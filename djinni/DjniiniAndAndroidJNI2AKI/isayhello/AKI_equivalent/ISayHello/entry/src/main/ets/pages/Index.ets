import hilog from '@ohos.hilog';
import testNapi from 'libentry.so'

enum Gender {
  Man,
  Woman
}

/*class ISayHello {
  finalize() {
    throw new Error('Method not implemented.')
  }

  public static readonly VERSION = 1

  // public sayHello(testInfo: MyRecord): string {
  //   // const str: string = testInfo.id + " " + testInfo.name + " " + testInfo.project + " " + testInfo.sex
  //   return "name2: " + testInfo.name + " project2: " + testInfo.project
  // }

  // @ts-ignore
  public static newInstance(): ISayHello {
    // return CppProxy.newInstance()
  }
}*/

/*// @ts-ignore
testNapi.JSBind.bindFunction("new ISayHello().finalize", new ISayHello().finalize)*/
// @ts-ignore
// testNapi.JSBind.bindFunction("new ISayHello().sayHello", new ISayHello().sayHello)
// @ts-ignore
// testNapi.JSBind.bindFunction("ISayHello.newInstance", ISayHello.newInstance)

// // @ts-ignore
// class CppProxy extends ISayHello {
//   private readonly nativeRef: number
//   private destroyed: boolean = false
//
//   constructor(nativeRef: number) {
//     super();
//     if (nativeRef === 0) {
//       throw new Error('nativeRef is zero')
//     }
//     this.nativeRef = nativeRef
//   }
//
//   // private nativeDestroy(nativeRef: number): void
//
//   // @ts-ignore
//   public _djinni_private_destroy(): void {
//     if (!this.destroyed) {
//       // this.nativeDestroy(this.nativeRef)
//       this.destroyed = true
//     }
//   }
//
//   protected finalize(): void {
//     this._djinni_private_destroy()
//     super.finalize()
//   }
//
//   public sayHello(testInfo: MyRecord): string {
//     if (this.destroyed) {
//       throw new Error('Object already destroyed')
//     }
//     return this.native_sayHello(this.nativeRef, testInfo)
//   }
//
//   // @ts-ignore
//   private native_sayHello(nativeRef: number, testInfo: MyRecord): string
//
//   // @ts-ignore
//   // public static newInstance(): ISayHello
// }
//
// // @ts-ignore
// // testNapi.JSBind.bindFunction("new CppProxy().nativeDestroy", new CppProxy().nativeDestroy)
// // @ts-ignore
// testNapi.JSBind.bindFunction("new CppProxy()._djinni_private_destroy", new CppProxy()._djinni_private_destroy)
// // @ts-ignore
// testNapi.JSBind.bindFunction("new CppProxy().finalize", new CppProxy().finalize)
// // @ts-ignore
// testNapi.JSBind.bindFunction("new CppProxy().sayHello", new CppProxy().sayHello)
// /*// @ts-ignore
// testNapi.JSBind.bindFunction("new CppProxy().native_sayHello", new CppProxy().native_sayHello)
// // @ts-ignore
// testNapi.JSBind.bindFunction("CppProxy.newInstance", CppProxy.newInstance)*/
//
/*class MyRecord {
  *//*package*//*
  id: number
  *//*package*//*
  name: string
  *//*package*//*
  project: string
  *//*package*//*
  sex: Gender

  constructor(id: number,
              name: string,
              project: string,
              sex: Gender) {
    this.id = id;
    this.name = name;
    this.project = project;
    this.sex = sex;
  }

  getId(): number {
    return this.id;
  }

  getName(): string {
    return MyRecord.name;
  }

  getProject(): string {
    return this.project;
  }

  getSex(): Gender {
    return this.sex;
  }

  toString(): string {
    return "com.ruturaj.huawei.isayhello.MyRecord{" +
      "id=" + this.id +
      "," + "name=" + MyRecord.name +
      "," + "project=" + this.project +
      "," + "sex=" + this.sex +
      "}";
  }
}*/

//
// // @ts-ignore
// testNapi.JSBind.bindFunction("new MyRecord().getId", new MyRecord().getId)
// // @ts-ignore
// testNapi.JSBind.bindFunction("new MyRecord().getName", new MyRecord().getName)
// // @ts-ignore
// testNapi.JSBind.bindFunction("new MyRecord().getProject", new MyRecord().getProject)
// // @ts-ignore
// testNapi.JSBind.bindFunction("new MyRecord().getSex", new MyRecord().getSex)
// // @ts-ignore
// testNapi.JSBind.bindFunction("new MyRecord().toString", new MyRecord().toString)

/*class TestDjinniWrapper implements ISayHello {
  sayHello: (testInfo: testNapi.MyRecord) => string
  newInstance: () => ISayHello

  // sayHello(testInfo: MyRecord): string {
  //   return `name1: ${testInfo.name} project1: ${testInfo.project}
  // }
}*/

// @ts-ignore
// testNapi.JSBind.bindFunction("new TestDjinniWrapper().sayHello", new TestDjinniWrapper().sayHello)

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
            hilog.error(0x0000, 'RRR', '%{public}d', testNapi.androidJNISayHello(1));

            // testNapi.androidJNISayHello(1)
            // testNapi.Gender.Man
            // testNapi.Gender.Woman
            // testNapi.MyRecord.length
            // testNapi.CppProxy.newInstance()
            // hilog.error(0x0000, 'RRR', '%{public}d', testNapi.ISayHello.newInstance());

            // const djnniInterface: ISayHello = ISayHello.newInstance();
            // hilog.error(0x0000, 'RRR', '%{public}d', djnniInterface);
            // const infoStore: MyRecord = new MyRecord(1234, "djinni test \n", "djinni", Gender.Man);
            // const a: string = djnniInterface.sayHello(infoStore);
            // // const a : string = testNapi.ISayHello.sa
            //
            // this.message = a


            /* var iSayHello = new testNapi.ISayHello()
             var sh = iSayHello.sayHello(new MyRecord(1234, "djinni test \n", "djinni", Gender.Man));
             // const a: string = testNapi.ISayHello.sayHello(new MyRecord(1234, "djinni test \n", "djinni", Gender.Man))
             this.message = sh*/

            var djnniInterface = new testNapi.TestDjinniWrapper()
            hilog.error(0x0000, 'RRR', '%{public}d', 2);
            var infoStore = new testNapi.MyRecord(1234, "djinni test \n", "djinni", Gender.Woman)
            hilog.error(0x0000, 'RRR', '%{public}d', 3);
            var a: string = djnniInterface.sayHello(infoStore)
            hilog.error(0x0000, 'RRR', '%{public}d', 4);
            this.message = a
            hilog.error(0x0000, 'RRR', '%{public}d', 5);

          })
      }
      .width('100%')
    }
    .height('100%')
  }
}