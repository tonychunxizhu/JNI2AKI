export const androidJNISayHello: (a: number) => void

export enum Gender {
  Man = 0,
  Woman = 1
}

export class ISayHello {
  // finalize: () => void

  static readonly VERSION = 1

  sayHello: (testInfo: MyRecord) => string

  newInstance: () => ISayHello
}

// export declare class CppProxy extends ISayHello {
//   private readonly nativeRef: number;
//   private destroyed: boolean;
//
//   constructor(nativeRef: number);
//
//   _djinni_private_destroy(): void;
//
//   sayHello(testInfo: MyRecord): string;
//
//   private native_sayHello(nativeRef: number, testInfo: MyRecord): string;
//
//   static newInstance(): ISayHello;
// }

export declare class MyRecord {
  id: number
  name: string
  project: string
  sex: Gender

  constructor(id: number, name: string, project: string, sex: Gender)

  getId: () => number

  getName: () => string

  getProject: () => string

  getSex: () => Gender

  toString: () => string
}
