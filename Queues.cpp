#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Person {
    int position;
    string name;

    Person(int pos, string name) : position(pos), name(name) {}
};

int main()
{
    int n = 0; //br hora
    int numGroups = 0;
    cin >> n >> numGroups;
    vector<queue<Person> > s;
    string nameholder;
    int gr = 0;
    int posi = 0;
    long long br = 0;
    queue<int> groupIndex;
    for (int i = 0; i < n; i++) {
        cin >> nameholder >> gr;
        queue<Person> q;
        Person ch(i, nameholder);
        if (s.at(gr).empty()) {
            groupIndex.push(gr);
        }
        s.at(gr).push(ch);

        if (br && br % 2 == 0) {
            nameholder = s.at(groupIndex.front()).front().name;
            posi = s.at(groupIndex.front()).front().position;
            s.at(groupIndex.front()).pop();
            cout << nameholder << " " << posi << " " << br << '\n';
            if (s.at(groupIndex.front()).size() == 0) {
                groupIndex.pop();
            }
        }
        br++;
    }

    while (groupIndex.size()) {
        if (br && br % 2 == 0) {
            nameholder = s.at(groupIndex.front()).front().name;
            posi = s.at(groupIndex.front()).front().position;
            s.at(groupIndex.front()).pop();
            cout << nameholder << " " << posi << " " << br << '\n';
            if (s.at(groupIndex.front()).size() == 0) {
                groupIndex.pop();
            }
        }
        br++;
    }
}
