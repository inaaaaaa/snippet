# -*- coding: utf-8 -*-


class State():
    @staticmethod
    def ret(x):
        return State(lambda s: (x, s))

    def __init__(self, f):
        self.f = f

    def __str__(self):
        return "State " + str(self.f)

    def bind(self, state):
        return State(lambda s:
                     (lambda r1, s1:
                      (lambda r2, s2:
                       (r2, s2))(*state(r1).runState(s1)))(*self.runState(s)))

    def get(self):
        return State(lambda s:
                     (lambda s1: (s1, s1))(self.execState(s)))

    def put(self, x):
        return State(lambda s: ((), x))

    def modify(self, f):
        return State(lambda s: ((), f(self.execState(s))))

    def runState(self, s):
        return self.f(s)

    def evalState(self, s):
        return self.runState(s)[0]

    def execState(self, s):
        return self.runState(s)[1]


if __name__ == '__main__':
    print(State
          .ret(10)
          .runState(0))  # (10, 0)

    print(State
          .ret(10)
          .bind(lambda x: State(lambda s: (-1, -1)))
          .runState(10))  # (-1, -1)

    print(State
          .ret(10)
          .bind(lambda x: State(lambda s: (-1, -1)))
          .bind(lambda x: State.ret(100))
          .runState(10))  # (100, -1)

    print(State
          .ret(10)
          .bind(lambda x: State(lambda s: (-1, s)))
          .runState(10))  # (-1, 10)

    print(State
          .ret(1)
          .get()
          .bind(lambda x: State(lambda s: (-1, -1)))
          .modify(lambda x: x + 9)
          .bind(lambda x: State(lambda s: (100, s)))
          .runState(10))  # (100, 8)
