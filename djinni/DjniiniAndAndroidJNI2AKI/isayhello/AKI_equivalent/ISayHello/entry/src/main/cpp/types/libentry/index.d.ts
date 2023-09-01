export const androidJNISayHello: (a: number) => void

export enum Gender {
  Man = 0,
  Woman = 1
}

export class ISayHello {
  static readonly VERSION = 1

  sayHello: (testInfo: MyRecord) => string

  newInstance: () => ISayHello
}

export class MyRecord {
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

export class TestDjinniWrapper extends ISayHello {
  sayHello: (testInfo: MyRecord) => string
  newInstance: () => ISayHello
}