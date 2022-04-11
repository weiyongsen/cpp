#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int able[5][3];
int b[500], minans = 50005;
int c[4];

void newanswer(int x, int y) {
    if (x*y <= minans) {
        if (x*y < minans){
            minans = x*y;
            memset(b, 0, sizeof(b));
        }
        int v = min(x, minans/x);
        if (b[minans/v]<=0) {
            b[v] = 1;
        }
    }
}

void case1(int step) {
    if (step == 4) {
        int cy = 0, cx = 0, i, x[4], y[4];
        for (i=0; i<4; i++) {
            x[i] = able[i][c[i]];
            y[i] = able[i][1-c[i]];
            if (y[i] > cy) {
                cy = y[i];
            }
            cx += x[i];
        }
        newanswer(cx, cy);
    }
    else {
        c[step] = 0;
        case1(step+1);
        c[step] = 1;
        case1(step+1);
    }
}

void case2(int emmm, int step) {
    if (step == 4) {
        int cy = 0, cx = 0, i, x[4], y[4];
        for (i=0; i<4; i++) {
            x[i] = able[i][c[i]];
            y[i] = able[i][1-c[i]];
        }
        for (i=0; i<4; i++) {
            if (i != emmm) {
                if (y[i] > cy) {
                    cy = y[i];
                }
                cx += x[i];
            }
        }
        newanswer(max(cx, y[emmm]), cy+x[emmm]);
    }
    else {
        c[step] = 0;
        case2(emmm, step+1);
        c[step] = 1;
        case2(emmm, step+1);
    }
}
void case3(int emmm, int rgt, int step) {
    if (step == 4) {
        int cy = 0, cx = 0, i, x[4], y[4];
        for (i=0; i<4; i++) {
            x[i] = able[i][c[i]];
            y[i] = able[i][1-c[i]];
        }
        for (i=0; i<4; i++) {
            if (i!=emmm && i!=rgt) {
                if (y[i] > cy) {
                    cy = y[i];
                }
                cx += x[i];
            }
        }
        newanswer(max(cx, y[emmm])+x[rgt], max(cy+x[emmm], y[rgt]));
    }
    else {
        c[step] = 0;
        case3(emmm, rgt, step+1);
        c[step] = 1;
        case3(emmm, rgt, step+1);
    }
}

void case4(int top, int emmm, int step) {
    if (step == 4) {
        int cy, cx, i, x[4], y[4];
        for (i=0; i<4; i++) {
            x[i] = able[i][c[i]];
            y[i] = able[i][1-c[i]];
        }
        cy = y[top] + y[emmm];
        cx = max(x[top], x[emmm]);
        for (i=0; i<4; i++) {
            if (i!=emmm && i!=top) {
                if (y[i] > cy) {
                    cy = y[i];
                }
                cx += x[i];
            }
        }
        newanswer(cx, cy);
    }
    else {
        c[step] = 0;
        case4(top, emmm, step+1);
        c[step] = 1;
        case4(top, emmm, step+1);
    }
}

void case6(int lft, int rgt, int top, int step) {
    if (step == 4) {
        int cx, cy, i, last, x[4], y[4];
        for (i=0; i<4; i++) {
            x[i] = able[i][c[i]];
            y[i] = able[i][1-c[i]];
            if (i!=lft && i!=rgt && i!=top) {
                last = i;
            }
        }
        if (x[top] > x[lft]) {
            return;
        }
        cx = x[lft] + x[rgt];
        cy = y[lft] + y[top];
        if (cy > y[rgt]) {
            if (y[lft] < y[rgt]) {
                if (x[top]+x[last] <= cx) {
                    cy = max(cy, y[rgt]+y[last]);
                }
                else {
                    return;
                }
            }
            else {
                if (x[top]+x[last] <= cx) {
                    cy = max(cy, y[lft]+y[last]);
                }
                else {
                    return;
                }
            }
        }
        else {
            if (x[last]+x[rgt] <= cx) {
                cy = max(cy+y[last], y[rgt]);
            }
            else {
                return;
            }
        }
        newanswer(cx, cy);
    }
    else {
        c[step] = 0;
        case6(lft, rgt, top, step+1);
        c[step] = 1;
        case6(lft, rgt, top, step+1);
    }
}

int main() {
    int i, j, k;
    for (i=0; i<4; i++) {
        cin >> able[i][0] >> able[i][1];
        if (able[i][0] > able[i][1]) {
            able[i][1] += able[i][0];
            able[i][0] = able[i][1] - able[i][0];
            able[i][1] -= able[i][0];
        }
    }
    
    case1(0);
    for (i=0; i<4; i++) {
        case2(i, 0);
    }
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            if (i != j) {
                case3(i, j, 0);
            }
        }
    }
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            if (i != j) {
                case4(i, j, 0);
            }
        }
    }
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            for (k=0; k<4; k++) {
                if (i != j && j != k && i != k) {
                    case6(i, j, k, 0);
                }
            }
        }
    }
    
    cout << minans << endl;
    for (i=1; i<201; i++) {
        if (b[i]) {
            cout << i << ' ' << minans/i << endl;
        }
    }
    
    return 0;
}
