#include "ConsoleCookPrinter.h"
#include <iostream>
using namespace std;

void ConsoleCookPrinter::print(const ICook& cook) const {
    cout << "Cook: " << cook.getName() << endl;
    cout << "Skill Level: " << cook.getSkillLevel() << endl;
    cout << "Experience: " << cook.getExperienceYears() << " years" << endl;
    cout << "Specialty: " << cook.getSpecialty() << endl;
    cout << "Age: " << cook.getAge() << endl;
    cout << "Awards: " << cook.getAwards() << endl;
    cout << "Available: " << (cook.getIsAvailable() ? "Yes" : "No") << endl;
}
