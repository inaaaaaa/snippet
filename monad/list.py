# -*- coding: utf-8 -*-


class List():
    @staticmethod
    def ret(x):
        return List([x])

    def __init__(self, x):
        self.x = x

    def __str__(self):
        return "List " + str(self.x)

    def bind(self, f):
        acc = []
        for i in self.x:
            acc = acc + f(i).x
        return List(acc)


if __name__ == '__main__':
    print(List.ret(100)
          .bind(lambda x: List.ret(x)
                .bind(lambda y: List.ret(y))))  # List [100]

    print(List.ret(100)
          .bind(lambda x: List.ret(200)
                .bind(lambda y: List.ret(x + y))))  # List [300]

    print(List.ret(100)
          .bind(lambda x: List([])
                .bind(lambda x: List([1, 2, 3, 4, 5])
                      .bind(lambda y: List.ret(x + y)))))  # List []

    print(List([1, 2, 3, 4, 5])
          .bind(lambda x: List.ret(x * 8)))  # List [8, 16, 24, 32, 40]

    print(List(list(range(1, 3)))
          .bind(lambda x: List(list("abc"))
                .bind(lambda y: List.ret((x, y)))))
    # List [(1, 'a'), (1, 'b'), (1, 'c'), (2, 'a'), (2, 'b'), (2, 'c')]
