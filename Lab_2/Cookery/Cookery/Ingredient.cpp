#include "Ingredient.h"

Ingredient::Ingredient(const string& n, double q, const string& u)
    : name(n), quantity(q), unit(u), supplier(""), expirationDate(""), storageLocation(""),
    pricePerUnit(0), category(""), organic(false) {}

string Ingredient::getName() const { return name; }
double Ingredient::getQuantity() const { return quantity; }
string Ingredient::getUnit() const { return unit; }

void Ingredient::setQuantity(double q) { quantity = q; }

void Ingredient::setSupplier(const string& s) { supplier = s; }
void Ingredient::setExpirationDate(const string& d) { expirationDate = d; }
void Ingredient::setStorageLocation(const string& l) { storageLocation = l; }
void Ingredient::setPricePerUnit(double p) { pricePerUnit = p; }
void Ingredient::setCategory(const string& c) { category = c; }
void Ingredient::setOrganic(bool o) { organic = o; }

string Ingredient::getSupplier() const { return supplier; }
string Ingredient::getExpirationDate() const { return expirationDate; }
string Ingredient::getStorageLocation() const { return storageLocation; }
double Ingredient::getPricePerUnit() const { return pricePerUnit; }
string Ingredient::getCategory() const { return category; }
bool Ingredient::isOrganic() const { return organic; }
