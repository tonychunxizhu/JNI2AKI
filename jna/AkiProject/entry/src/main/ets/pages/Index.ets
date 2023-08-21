import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

var num = 100.00;
num = testNapi.changeDouble();

testNapi.add1(5, 5)

function setName(n) {
  name = n;
}
var name = "abcd";
testNapi.changeName();
// @ts-ignore
testNapi.JSBind.bindFunction("set", setName)



// var name = new ArrayBuffer(64);
// var UintName = new BigUint64Array(name);
// name[0] = 'a';
// name[1] = 'b';
// name[2] = 'c';
// name[3] = 'd';
// testNapi.changeName(name);
// var test = UintName.toString();
var name2 = "abcd";
name2 = testNapi.changeName2();


var age = new ArrayBuffer(1);
var UintAge = new Uint8Array(age);
UintAge[0] = 21;
testNapi.changeNum(age)
var msg = UintAge.toString();
// var result = testNapi.changeNum(age);
// UintAge = new Uint8Array(result);
// var msg = UintAge.toString();
class AddNumber {
  add(num1: number, num2: number): number {
    return num1 + num2;
  }
  show(s: string, num: number): string {
    return num + s;
  }
}
// @ts-ignore
testNapi.JSBind.bindFunction("AddNumber.add", new AddNumber().add);
// @ts-ignore
testNapi.JSBind.bindFunction("AddNumber.show", new AddNumber().show);

var s = new testNapi.MyStructure();
s = testNapi.MakeMyStructure(2, 3);
var result = testNapi.add(s);

@Entry
@Component
struct Index {
  @State message: string = 'JNA'

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            hilog.info(0x0000, 'testTag', 'Test name = %{public}s', name);
            hilog.info(0x0000, 'testTag', 'Test name1 = %{public}s', name2);
            hilog.info(0x0000, 'testTag', 'Test num = %{public}d', num);
            hilog.info(0x0000, 'testTag', 'Test age = %{public}s', msg);
            hilog.info(0x0000, 'testTag', 'Test final number = %{public}d', testNapi.add1(5, 5));
            testNapi.addN();
            testNapi.show();
            var area = testNapi.calculateArea(3, 4);
            var perimeter = testNapi.calculatePerimeter(3, 4);
            hilog.info(0x0000, 'testTag', 'Test area = %{public}d', area);
            hilog.info(0x0000, 'testTag', 'Test perimeter = %{public}d', perimeter);
            hilog.info(0x0000, 'testTag', 'Test Result = %{public}d', result);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
