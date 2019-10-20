#include <iostream>
using namespace std;

string n1, n2;

void getAnswer();

int getValueFromNumber(char number) {
    return number - '0';
}

int getValueFromLetter(char letter) {
    return letter - 'A' + 10;
}

int transformedNumberToBase(const string& number, int base){
    int transformedNumber = 0, currentPow = 1;
    for (int i = number.size() - 1; i >=0 ; i--) {
        isalpha(number[i]) ? transformedNumber += getValueFromLetter(number[i]) * currentPow :
                transformedNumber += getValueFromNumber(number[i]) * currentPow;
        currentPow *= base;
    }
    return transformedNumber;
}

int getNumberMinBase(const string& number){
    int base = 1;
    for (char i : number) {
        isalpha(i) ? base = base > getValueFromLetter(i) ? base : getValueFromLetter(i) :
                base = base > getValueFromNumber(i) ? base : getValueFromNumber(i);
    }
    return base + 1;
}

void getAnswer() {
    int n1Base = getNumberMinBase(n1);
    int n2Base = getNumberMinBase(n2);
    bool answerGotten = false;
    for (; n1Base <= 36 and !answerGotten; ++n1Base)
        for (int i = n2Base; i <= 36 and !answerGotten; i++) {
            if (transformedNumberToBase(n1, n1Base) == transformedNumberToBase(n2, i)){
                answerGotten = true;
                cout << n1 << " (base " << n1Base << ") = " << n2 << " (base " << i << ")" << endl;
            }
        }
    if (!answerGotten) cout << n1 << " is not equal to " << n2 << " in any base 2..36" << endl;
}

int main() {
    while (cin >> n1 >> n2){
        getAnswer();
    }
}
