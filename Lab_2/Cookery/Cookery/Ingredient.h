#pragma once
#include <string>
using namespace std;

class Ingredient {
private:
    string name;
    double quantity;
    string unit;

    string supplier;
    string expirationDate;
    string storageLocation;
    double pricePerUnit;
    string category;
    bool organic;

public:
    Ingredient(const string& n, double q, const string& u);

    string getName() const;
    double getQuantity() const;
    string getUnit() const;

    void setQuantity(double q);

    void setSupplier(const string& s);
    void setExpirationDate(const string& d);
    void setStorageLocation(const string& l);
    void setPricePerUnit(double p);
    void setCategory(const string& c);
    void setOrganic(bool o);

    string getSupplier() const;
    string getExpirationDate() const;
    string getStorageLocation() const;
    double getPricePerUnit() const;
    string getCategory() const;
    bool isOrganic() const;
};
