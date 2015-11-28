# -*- coding: utf-8 -*-


class Maybe():
    @staticmethod
    def ret(x):
        return Just(x)


class Just():
    def __init__(self, x):
        self.x = x

    def __str__(self):
        return "Just " + str(self.x)

    def bind(self, f):
        return f(self.x)


class Nothing():
    def __init__(self):
        pass

    def __str__(self):
        return "Nothing"

    def bind(self, f):
        return Nothing()


if __name__ == '__main__':
    print(Maybe.ret(10)
          .bind(lambda x: Just(x * 8)
                .bind(lambda x: Just(x * 8))))  # Just 640

    print(Maybe.ret(10)
          .bind(lambda x: Just(x * 8)
                .bind(lambda x: Nothing()
                      .bind(lambda x: Just(x * 8)))))  # Nothing

    print(Just(1)
          .bind(lambda a: Just(a * 2)))  # Just 2

    print(Just(1)
          .bind(lambda a: Nothing()
                .bind(lambda b: Just(a * b))))  # Nothing
