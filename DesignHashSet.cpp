#include <vector>
#include <list>
using namespace std;

class MyHashSet {
private:
    static const int SIZE = 1009; // Número primo para distribuir mejor
    vector<list<int>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() {
        table.resize(SIZE);
    }

    void add(int key) {
        int h = hash(key);
        for (int val : table[h]) {
            if (val == key) return; // Ya existe, no agregamos
        }
        table[h].push_back(key);
    }

    void remove(int key) {
        int h = hash(key);
        table[h].remove(key); // list::remove elimina todas las ocurrencias del valor
    }

    bool contains(int key) {
        int h = hash(key);
        for (int val : table[h]) {
            if (val == key) return true;
        }
        return false;
    }
};
