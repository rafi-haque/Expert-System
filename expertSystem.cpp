#include <iostream>

#include "rules.h"

using namespace std;

int main() {
    cout << "Welcome to the Detection-Treatment program for toxic substances and poisons!\n\n\n";
    Rules poisonDiagnosis = Rules();

    poisonDiagnosis.start_iteration();
    return 0;
};
