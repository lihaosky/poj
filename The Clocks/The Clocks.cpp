#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct Clock
{
    string path;
    int state[9];
};

int mo[10][9] = {
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 1, 0, 1, 1, 0, 0, 0, 0},
{1, 1, 1, 0, 0, 0, 0, 0, 0},
{0, 1, 1, 0, 1, 1, 0, 0, 0},
{1, 0, 0, 1, 0, 0, 1, 0, 0},
{0, 1, 0, 1, 1, 1, 0, 1, 0},
{0, 0, 1, 0, 0, 1, 0, 0, 1},
{0, 0, 0, 1, 1, 0, 1, 1, 0},
{0, 0, 0, 0, 0, 0, 1, 1, 1},
{0, 0, 0, 0, 1, 1, 0, 1, 1}
};

bool isFound(Clock& clock)
{
    for (int i = 0; i < 9; i++) {
        if (clock.state[i] != 0) {
            return false;
        }
    }
    return true;
}

Clock nextMove(Clock& tmp, int k)
{
    Clock m;
    for (int i = 0; i < 9; i++) {
        m.state[i] = (tmp.state[i] + mo[k][i]) % 4;
    }
    char c = k + 48;
    m.path += tmp.path;
    m.path += c;
    return m;
}

int main()
{
    queue<Clock> q;
    Clock start;
    for (int i = 0; i < 9; i++) {
        cin >> start.state[i];
    }
    q.push(start);
    while (1) {
        Clock tmp = q.front();
        q.pop();
        for (int i = 1; i < 10; i++) {
            Clock m = nextMove(tmp, i);
            if (isFound(tmp)) {
                for (int i = 0; i < tmp.path.length(); i++) {
                    cout << tmp.path[i] << " ";
                }
                cout << endl;
                return 0;
            }
            q.push(m);
        }
    }
}
