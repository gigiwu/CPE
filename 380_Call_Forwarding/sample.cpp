//uva380
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class ele {
public:
    int time, target, end;
    ele() : time(0), target(0), end(0) {}
    ele(int time, int duration, int target) {
        this->time = time;
        this->target = target;
        this->end = time + duration;
    }
};
vector<ele> phone[10000];
bool isCalled[10000];

int TryCall(int time, int source) {
    isCalled[source] = true;
    for (int i = 0; i < phone[source].size(); ++i) {
        if (phone[source][i].time <= time && time <= phone[source][i].end) {
            if (isCalled[phone[source][i].target])
                return 9999;
            return TryCall(time, phone[source][i].target);
        }
    }
    return source;
}

int main() {
    cout << "CALL FORWARDING OUTPUT" << endl;
    int N;
    int cas = 0;
    cin >> N;

    while (N--) {
        cout << "SYSTEM " << ++cas << endl;
        int source, time, duration, target;
        for (int i = 0; i < 10000; ++i)
            phone[i].clear();

        while (cin >> source && source) {
            cin >> time >> duration >> target;
            phone[source].push_back(ele(time, duration, target));
        }
        while (cin >> time && time != 9000) {
            cin >> source;
            memset(isCalled, false, sizeof(isCalled));
            printf("AT %04d CALL TO %04d RINGS %04d\n", time, source, TryCall(time, source));
        }
    }

    cout << "END OF OUTPUT" << endl;
    return 0;
}