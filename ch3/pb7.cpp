#include <iostream>
#include <queue>

using namespace std;

class Shelter {
private:
    queue<int> cats, dogs;
public:
    void addCat(int t);
    void addDog(int t);
    int getCat();
    int getDog();
    int getAnimal();
};

void Shelter :: addCat(int t) {
    cats.push(t);
}

void Shelter :: addDog(int t) {
    dogs.push(t);
}

int Shelter :: getCat () {
    if (cats.empty()) {
        cout << "No more cats in the shelter." << endl;
        return -1;
    }
    int val = cats.front();
    cats.pop();
    return val;
}

int Shelter :: getDog () {
    if (dogs.empty()) {
        cout << "No more dogs in the shelter." << endl;
        return -1;
    }
    int val = dogs.front();
    dogs.pop();
    return val;
}

int Shelter :: getAnimal () {
    if (cats.empty() && dogs.empty()) {
        cout << "No more animals in the shelter." << endl;
        return -1;
    } else if (cats.empty() && !dogs.empty()) {
        cout << "No more cats!!" << endl;
        return getDog();
    } else if (dogs.empty() && !cats.empty()) {
        cout << "No more dogs!!" << endl;
        return getCat();
    } else {
        int val = cats.front();
        if (dogs.front() < val) {
            val = dogs.front();
            dogs.pop();
        } else {
            cats.pop();
        }
        return val;
    }
}

int main () {
    Shelter s;
    for (int i = 0; i < 21; i++) {
        if (i % 2) s.addCat(i);
        else s.addDog(i);
    }
    for (int i = 0; i < 7; i++) {
        cout << s.getCat() << endl;
    }
    for (int i = 0; i < 5; i++) {
        cout << s.getDog() << endl;
    }
    for (int i = 0; i < 10; i++) {
        cout << s.getAnimal() << endl;
    }
}