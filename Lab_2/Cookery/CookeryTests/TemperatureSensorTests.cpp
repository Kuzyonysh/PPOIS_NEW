#include "gtest/gtest.h"
#include "D:\Projects\Cookery\Cookery\TemperatureSensor.h"
#include "D:\Projects\Cookery\Cookery\TemperatureController.h"
#include "D:\Projects\Cookery\Cookery\ConsolePrinterTemperatureSensor.h"
#include <sstream>
#include <iostream>

using namespace std;

TEST(TemperatureSensorTest, ConstructorSetsValues) {
    TemperatureSensor sensor(0, 100, 25, "Oven", "digital");

    EXPECT_EQ(sensor.getCurrentTemperature(), 25);
    EXPECT_EQ(sensor.getMinSafe(), 0);
    EXPECT_EQ(sensor.getMaxSafe(), 100);
    EXPECT_EQ(sensor.getSensorLocation(), "Oven");
    EXPECT_EQ(sensor.getSensorType(), "digital");
}

TEST(TemperatureSensorTest, SetAndGetCurrentTemperature) {
    TemperatureSensor sensor;
    sensor.setCurrentTemperature(37.5);

    EXPECT_DOUBLE_EQ(sensor.getCurrentTemperature(), 37.5);
}

TEST(TemperatureSensorTest, SetAndGetSensorLocation) {
    TemperatureSensor sensor;
    sensor.setSensorLocation("Fridge");

    EXPECT_EQ(sensor.getSensorLocation(), "Fridge");
}

TEST(TemperatureSensorTest, SetAndGetSensorType) {
    TemperatureSensor sensor;
    sensor.setSensorType("analog");

    EXPECT_EQ(sensor.getSensorType(), "analog");
}

TEST(TemperatureControllerTest, MeasureUpdatesSensor) {
    TemperatureSensor sensor;
    TemperatureController controller(sensor);

    controller.measure(50);
    EXPECT_DOUBLE_EQ(sensor.getCurrentTemperature(), 50);
}

TEST(TemperatureControllerTest, CheckSafetyWithinLimits) {
    TemperatureSensor sensor(0, 100, 50);
    TemperatureController controller(sensor);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    controller.checkSafety();

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_NE(output.find("Temperature is within safe limits."), string::npos);
}

TEST(TemperatureControllerTest, CheckSafetyAboveMax) {
    TemperatureSensor sensor(0, 100, 150);
    TemperatureController controller(sensor);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    controller.checkSafety();

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_NE(output.find("Warning! Temperature is outside safe limits!"), string::npos);
}

TEST(TemperatureControllerTest, CheckSafetyBelowMin) {
    TemperatureSensor sensor(10, 100, 5);
    TemperatureController controller(sensor);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    controller.checkSafety();

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_NE(output.find("Warning! Temperature is outside safe limits!"), string::npos);
}

TEST(TemperatureControllerTest, CalibratePrintsLocation) {
    TemperatureSensor sensor(0, 100, 25, "Kitchen", "digital");
    TemperatureController controller(sensor);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    controller.calibrate();

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_NE(output.find("Calibrating sensor at location: Kitchen"), string::npos);
}

TEST(ConsolePrinterTemperatureSensorTest, PrintOutputsCorrectText) {
    TemperatureSensor sensor(0, 100, 25, "Oven", "digital");
    ConsolePrinterTemperatureSensor printer;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    printer.print(sensor);

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_NE(output.find("Sensor type: digital"), string::npos);
    EXPECT_NE(output.find("Sensor location: Oven"), string::npos);
    EXPECT_NE(output.find("Current temperature: 25"), string::npos);
}

TEST(TemperatureSensorTest, NegativeTemperatureAllowed) {
    TemperatureSensor sensor(-50, 100, -20);
    EXPECT_DOUBLE_EQ(sensor.getCurrentTemperature(), -20);
    EXPECT_DOUBLE_EQ(sensor.getMinSafe(), -50);
}

TEST(TemperatureSensorTest, ZeroTemperature) {
    TemperatureSensor sensor(0, 100, 0);
    EXPECT_DOUBLE_EQ(sensor.getCurrentTemperature(), 0);
}

TEST(TemperatureControllerTest, MultipleMeasurementsUpdateTemperature) {
    TemperatureSensor sensor;
    TemperatureController controller(sensor);

    controller.measure(10);
    controller.measure(20);
    controller.measure(30);

    EXPECT_DOUBLE_EQ(sensor.getCurrentTemperature(), 30);
}

TEST(ConsolePrinterTemperatureSensorTest, PrintAfterUpdatingTemperature) {
    TemperatureSensor sensor(0, 100, 20, "Freezer", "analog");
    ConsolePrinterTemperatureSensor printer;

    sensor.setCurrentTemperature(5);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    printer.print(sensor);

    cout.rdbuf(oldCout);
    string output = buffer.str();

    EXPECT_NE(output.find("Current temperature: 5"), string::npos);
    EXPECT_NE(output.find("Sensor location: Freezer"), string::npos);
    EXPECT_NE(output.find("Sensor type: analog"), string::npos);
}

TEST(TemperatureSensorTest, MinMaxSafeValues) {
    TemperatureSensor sensor(-10, 200, 50);
    EXPECT_DOUBLE_EQ(sensor.getMinSafe(), -10);
    EXPECT_DOUBLE_EQ(sensor.getMaxSafe(), 200);
}

TEST(TemperatureControllerTest, SafetyCheckEdgeCaseMin) {
    TemperatureSensor sensor(10, 100, 10);
    TemperatureController controller(sensor);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    controller.checkSafety();
    cout.rdbuf(oldCout);

    EXPECT_EQ(sensor.getCurrentTemperature(), 10);
}

TEST(TemperatureControllerTest, SafetyCheckEdgeCaseMax) {
    TemperatureSensor sensor(10, 100, 100);
    TemperatureController controller(sensor);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    controller.checkSafety();
    cout.rdbuf(oldCout);

    EXPECT_EQ(sensor.getCurrentTemperature(), 100);
}


TEST(TemperatureSensorTest, SpecialCharactersInSensorType) {
    TemperatureSensor sensor(0, 100, 20, "Lab", "therm@meter");
    EXPECT_EQ(sensor.getSensorType(), "therm@meter");
}
