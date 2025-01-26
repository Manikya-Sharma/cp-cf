#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';

class Rectangle {
   public:
    // x1, y1: topright
    // x2, y2: bottomleft
    int x1, x2, y1, y2;
    long long area() {
        if (x2 < x1 || y2 < y1)
            return 0;
        return (x1 - x2) * 1ll * (y1 - y2);
    }
    Rectangle intersection(Rectangle& r2) {
        Rectangle result;
        result.x1 = max(x1, r2.x1);
        result.x2 = min(x2, r2.x2);
        result.y1 = max(y1, r2.y1);
        result.y2 = min(y2, r2.y2);
        return result;
    }
};

int main() {
    Rectangle white, b1, b2;
    cin >> white.x1 >> white.y1 >> white.x2 >> white.y2;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;

    Rectangle bw1 = white.intersection(b1);
    if (bw1.area() == white.area()) {
        cout << "NO" << nl;
        return 0;
    }

    Rectangle bw2 = white.intersection(b2);
    if (bw2.area() == white.area()) {
        cout << "NO" << nl;
        return 0;
    }

    Rectangle bb_intersection = bw1.intersection(bw2);

    long long available_white_area = white.area() - bw1.area() - bw2.area() +
                                     white.intersection(bb_intersection).area();

    if (available_white_area > 0) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }

    return 0;
}
