#pragma once
#include <stdexcept>
#include <string>
using namespace std;

class CookingException {
protected:
    string message;
public:
    CookingException(string msg) : message(msg) {}
    virtual const char* what() const noexcept {
        return message.c_str();
    }
    virtual ~CookingException() = default;
};
class InvalidIngredientAmountException : public runtime_error {
public:
    explicit InvalidIngredientAmountException(const string& msg)
        : runtime_error(msg) {}
};
class DuplicateIngredientException : public CookingException {
public:
    DuplicateIngredientException(string msg)
        : CookingException("Duplicate ingredient: " + msg) {}
};
class DuplicateDishException : public CookingException {
public:
    DuplicateDishException(string msg)
        : CookingException("Duplicate dish: " + msg) {}
};
class DishNotFoundException : public CookingException {
public:
    DishNotFoundException(string msg)
        : CookingException("Dish not found: " + msg) {}
};
class InvalidTemperatureException : public CookingException {
public:
    InvalidTemperatureException(string msg)
        : CookingException("Invalid temperature  for oven" + msg) {}
};
class InvalidTimeException : public CookingException {
public:
    InvalidTimeException(string msg)
        :CookingException("Invalid cooking time" + msg) {}
};
class OvenException :public CookingException {
public:
    OvenException(string msg)
        :CookingException("Oven error : " + msg) {}
};
class InvalidModeException : public CookingException {
public:
    InvalidModeException(string msg)
        : CookingException("Invalid oven mode:" + msg) {}
};
class InvalidDiameterException : public CookingException {
public:
    InvalidDiameterException(string msg)
        : CookingException("Invalid pen diameter:" + msg) {}
};
class DuplicateWorkplaceException : public CookingException {
public:
    DuplicateWorkplaceException(string msg)
        : CookingException("Duplicate workplace: " + msg) {}
};
class NotEnoughTemperatureException : public CookingException {
public:
    NotEnoughTemperatureException(const string& msg)
        : CookingException("Not enough temperature: " + msg) {}
};
class FridgeOverflowException : public CookingException {
public:
    FridgeOverflowException(const string& msg)
        : CookingException("Fridge is full! Can't add: " + msg) {}
};

