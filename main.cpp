#include <iostream>
#include <random>
#include <vector>
#include <ctime>

using namespace std;

template <class T>
T sort(vector<T>& list, unsigned long SIZE) {
    //Falls eine leerer oder nur mit einem Wert befüllten Container kommt, wird dies hier abgefangen.
    if(SIZE <= 1) return -999;

    vector<T> left;
    vector<T> right;
    left.reserve(SIZE / 2);

    for (int i = 0; i < SIZE/2; ++i) {
        left.push_back(list[i]);
    }

    for (int i = static_cast<int>(SIZE / 2); i < SIZE; ++i) {
        right.push_back(list[i]);
    }

    sort(left, SIZE/2);
    sort(right, (SIZE+1)/2);

    T *posL = &left[0];
    T *posR = &right[0];

    for (int j = 0; j < SIZE; ++j) {
//        Überprüfen, welches kleiner ist und diesen Wert ins den Hauptvector einfügen
        if (*posL <= *posR) {
            list[j] = *posL;

            if (posL != &right[(SIZE+1)/2 - 1]) {
                if(posL == &left[SIZE/2 - 1]){
                    posL = &right[(SIZE+1)/2 - 1];
                }
                else{
                    ++posL;
                }
            }
        } else {
            list[j] = *posR;
            if (posR == &right[(SIZE + 1) / 2 - 1]) {
                posR = &left[SIZE / 2 - 1];
            } else {
                ++posR;
            }
        }
    }

    return 0;
}

template <class T>
void print(vector<T> & list, unsigned long SIZE) {
    for (int i = 0; i < SIZE; ++i) {
        cout << list[i] << "\t";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    vector<float> list;
    unsigned long SIZE = 1000;
    list.reserve(SIZE);

    for (int i = 0; i < SIZE; ++i) {
        list.emplace_back(rand() % 1000);
    }

    sort(list, SIZE);
    print(list, SIZE);

    return 0;
}
