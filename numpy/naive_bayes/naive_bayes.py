#!/usr/bin/env python3
# encoding:utf-8

# study of http://www.kamishima.net/mlmpyja/

import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
import sklearn as skl

class NaiveBayes1(object):
    def __init__(self):
        self.pY_ = None
        self.pXgY_ = None


    def fit(self, X, y):
        n_samples = X.shape[0]
        n_features = X.shape[1]
        n_classes = 2
        n_fvalues = 2

        if n_samples != len(y):
            raise ValueError('Mismatched number of samples.')

        nY = np.zeros(n_classes, dtype=np.int)
        for i in range(n_samples):
            nY[y[i]] += 1

        self.pY_ = np.empty(n_classes, dtype=np.float)
        for i in range(n_classes):
            self.pY_[i] = nY[i] / np.float(n_samples)

        nXY = np.zeros((n_features, n_fvalues, n_classes), dtype=np.int)
        for i in range(n_samples):
            for j in range(n_features):
                nXY[j, X[i, j], y[i]] += 1

        self.pXgY_ = np.empty((n_features, n_fvalues, n_classes), dtype=np.float)
        for j in range(n_features):
            for xi in range(n_fvalues):
                for yi in range(n_classes):
                    self.pXgY_[j, xi, yi] = nXY[j, xi, yi] / np.float(nY[yi])


    def predict(self, X):
        n_samples = X.shape[0]
        n_features = X.shape[1]

        y = np.empty(n_samples, dtype=np.int)
        for i, xi in enumerate(X):
            logpXY = np.log(self.pY_) + \
                     np.sum(np.log(self.pXgY_[np.arange(n_features), xi, :]), axis=0)
            y[i] = np.argmax(logpXY)

        return y


def main():
    data = np.genfromtxt('vote_filled.tsv', dtype=np.int)
    X = data[:, :-1]
    y = data[:, -1]
    clr = NaiveBayes1()
    clr.fit(X, y)
    size = data.shape[0]
    correct = 0
    predict_y = clr.predict(X[:, :])
    for i in range(size):
        if y[i] == predict_y[i]:
            correct += 1
        print(i, y[i], predict_y[i])

    print("rate : " + str(float(correct) / size))

if __name__ == '__main__':
    main()
