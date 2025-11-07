#include "PrinterTrainer.h"

void PrinterTrainer::print(const ITrainer& t) const {
    cout << "Trainer Info" << endl;
    cout << "Name: " << t.getName() << endl;
    cout << "Gender: " << t.getGender() << endl;
    cout << "Age: " << t.getAge() << endl;
    cout << "Specialization: " << t.getSpecialization() << endl;
    cout << "Experience: " << t.getExperience() << " years" << endl;
    cout << "Salary: " << t.getSalary() << " $" << endl;
    cout << "Available: " << (t.getAvailability() ? "Yes" : "No") << endl;
    cout << "Clients: " << t.getClientsCount() << endl;
    cout << "Rating: " << t.getRating() << "/5" << endl;
    cout << "Contact: " << t.getContact() << endl;
}
