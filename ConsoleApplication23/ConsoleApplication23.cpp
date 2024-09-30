#include <iostream>
#include <string>

using namespace std;

class Instrument {
protected:
    string name;
    int yearOfInvention;

public:
    Instrument(string name, int yearOfInvention) : name(name), yearOfInvention(yearOfInvention) {}

    virtual void playSound() = 0;
    virtual void adjustVolume() = 0;

    string getName() const {
        return name;
    }

    int getYearOfInvention() const {
        return yearOfInvention;
    }
};

class StringInstrument : public Instrument {
private:
    int numberOfStrings;

public:
    StringInstrument(string name, int yearOfInvention, int numberOfStrings)
        : Instrument(name, yearOfInvention), numberOfStrings(numberOfStrings) {}

    void playSound() override {
        cout << "Граємо на струнному інструменті " << getName() << " із " << numberOfStrings << " струнами." << endl;
    }

    void adjustVolume() override {
        cout << "Регулюємо гучність струнного інструменту " << getName() << "." << endl;
    }
};

class WindInstrument : public Instrument {
private:
    string typeOfReed;

public:
    WindInstrument(string name, int yearOfInvention, string typeOfReed)
        : Instrument(name, yearOfInvention), typeOfReed(typeOfReed) {}

    void playSound() override {
        cout << "Граємо на духовому інструменті " << getName() << " із типом духового отвору " << typeOfReed << "." << endl;
    }

    void adjustVolume() override {
        cout << "Регулюємо гучність духового інструменту " << getName() << "." << endl;
    }
};

class PercussionInstrument : public Instrument {
private:
    string typeOfStrikingSurface;

public:
    PercussionInstrument(string name, int yearOfInvention, string typeOfStrikingSurface)
        : Instrument(name, yearOfInvention), typeOfStrikingSurface(typeOfStrikingSurface) {}

    void playSound() override {
        cout << "Граємо на ударному інструменті " << getName() << " із типом ударної частини " << typeOfStrikingSurface << "." << endl;
    }

    void adjustVolume() override {
        cout << "Регулюємо гучність ударного інструменту " << getName() << "." << endl;
    }
};

int main() {
    Instrument* instruments[] = {
        new StringInstrument("Скрипка", 1550, 4),
        new WindInstrument("Кларнет", 1700, "одинарний"),
        new PercussionInstrument("Барабан", 5000, "дерев'яна")
    };

    for (Instrument* instrument : instruments) {
        instrument->playSound();
        instrument->adjustVolume();
        cout << endl;
    }

    for (Instrument* instrument : instruments) {
        delete instrument;
    }

    return 0;
}