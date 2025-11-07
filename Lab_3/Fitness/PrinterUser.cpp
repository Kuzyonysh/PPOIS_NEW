#include "PrinterUser.h"

void PrinterUser::print(const IUser& user) const {
    std::cout << "Name: " << user.getName() << std::endl;
    std::cout << "Age: " << user.getAge() << std::endl;
    std::cout << "Weight: " << user.getWeight() << std::endl;
    std::cout << "Height: " << user.getHeight() << std::endl;
    std::cout << "Gender: " << user.getGender() << std::endl;
    std::cout << "Activity: " << user.getActivity() << std::endl;
}
