#include "PrinterBodyMetrics.h"

PrinterBodyMetrics::PrinterBodyMetrics(const BodyMetricsManager& m) : manager(m) {}

void PrinterBodyMetrics::print(const BodyMetrics& record) const {
    cout << "Date: " << record.getDate() << endl;
    cout << "Weight: " << record.getWeight() << " kg" << endl;
    cout << "Height: " << record.getHeight() << " cm" << endl;
    cout << "Waist: " << record.getWaist() << " cm" << endl;
    cout << "Hips: " << record.getHips() << " cm" << endl;
}
