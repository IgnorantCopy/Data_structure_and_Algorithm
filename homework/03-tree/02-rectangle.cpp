//
// Created by Ignorant on 2024/11/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rectangle {
    int y1;
    int y2;
    Rectangle(int y1, int y2) :y1(y1), y2(y2) {}
};

struct Node {
    int numOfSegments = 0;
    int len = 0;
    int maxLength = 0;
};

struct X {
    int x;
    int index;
    int flag;
    X(int x, int index, int flag) : x(x), index(index), flag(flag) {}
};

int numOfYSeg = 0;

void createTree(Node *tree, int *ys, int left, int right, int index) {
    if (left == right - 1) {
        tree[index].maxLength = ys[right] - ys[left];
        return;
    }
    int mid = (left + right) / 2;
    createTree(tree, ys, left, mid, 2 * index + 1);
    createTree(tree, ys, mid, right, 2 * index + 2);
    tree[index].maxLength = tree[2 * index + 1].maxLength + tree[2 * index + 2].maxLength;
}

void updateTree(Node *tree, int index) {
    if (tree[index].numOfSegments > 0) {
        tree[index].len = tree[index].maxLength;
    } else {
        tree[index].len = (2 * index + 1 >= 4 * numOfYSeg + 20 ? 0 : tree[2 * index + 1].len) +
                          (2 * index + 2 >= 4 * numOfYSeg + 20 ? 0 : tree[2 * index + 2].len);
    }
}

void mergeY(Node *tree, int *ys, int left, int right, int globalLeft, int globalRight, int index, int flag) {
    if (ys[left] >= globalRight || ys[right] <= globalLeft) {
        return;
    }
    if (globalLeft <= ys[left] && ys[right] <= globalRight) {
        tree[index].numOfSegments += flag;
        updateTree(tree, index);
        return;
    }
    int mid = (left + right) / 2;
    mergeY(tree, ys, left, mid, globalLeft, globalRight, 2 * index + 1, flag);
    mergeY(tree, ys, mid, right, globalLeft, globalRight, 2 * index + 2, flag);
    updateTree(tree, index);
}

int main() {
    int n = 0;
    cin >> n;
    vector<X> xs;
    auto *ys = new int[n * 2];
    vector<Rectangle> rectangles;
    for (int i = 0; i < n; i++) {
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        rectangles.emplace_back(y1, y2);
        xs.emplace_back(x1, i, 1);
        xs.emplace_back(x2, i, -1);
        ys[i * 2] = y1;
        ys[i * 2 + 1] = y2;
    }
    sort(xs.begin(), xs.end(), [](X a, X b) {
        return a.x < b.x;
    });
    sort(ys, ys + n * 2);
    numOfYSeg = unique(ys, ys + n * 2) - ys - 1;
    auto *tree = new Node[4 * numOfYSeg + 20];
    createTree(tree, ys, 0, numOfYSeg, 0);
    long long area = 0;
    for (int left = 0; left < xs.size(); left++) {
        int right = left;
        while (right + 1 < xs.size() && xs[right + 1].x == xs[left].x) {
            right++;
        }
        if (right + 1 == xs.size()) {
            break;
        }
        for (int i = left; i <= right; i++) {
            int index = xs[i].index;
            int flag = xs[i].flag;
            mergeY(tree, ys, 0, numOfYSeg, rectangles[index].y1, rectangles[index].y2, 0, flag);
        }
        area += (long long)(tree[0].len) * (long long)(xs[right + 1].x - xs[right].x);
        left = right;
    }
    cout << area << endl;
    delete[] tree;
    delete[] ys;
    return 0;
}
