#include "gtest/gtest.h"
#include "D:/Projects/Cookery/Cookery/Oven.h"
#include "D:/Projects/Cookery/Cookery/OvenManager.h"
#include "D:\Projects\Cookery\Cookery\ConsoleOvenPrinter.h"
#include <sstream>
#include <iostream>

using namespace std;


TEST(OvenTest, ConstructorSetsDefaultValues) {
    Oven oven;

    EXPECT_EQ(oven.getTemperature(), 0);
    EXPECT_EQ(oven.getMode(), "");
    EXPECT_EQ(oven.getCookingTime(), 0);
    EXPECT_FALSE(oven.getPowerState());
    EXPECT_TRUE(oven.getDoorState());
    EXPECT_EQ(oven.getBrand(), "Generic");
    EXPECT_EQ(oven.getPower(), 2.0);
    EXPECT_EQ(oven.getColor(), "white");
    EXPECT_EQ(oven.getMaterial(), "steel");
    EXPECT_EQ(oven.getCapacity(), 50);
    EXPECT_EQ(oven.getWidth(), 60.0);
    EXPECT_EQ(oven.getHeight(), 45.0);
    EXPECT_EQ(oven.getDepth(), 55.0);
    EXPECT_TRUE(oven.hasTimerFunction());
    EXPECT_TRUE(oven.hasLightFunction());
}

TEST(OvenTest, SettersAndGettersWorkCorrectly) {
    Oven oven;
    oven.setTemperature(200);
    oven.setMode("baking");
    oven.setCookingTime(30);
    oven.setDoorState(false);
    oven.setPowerState(true);
    oven.setColor("black");
    oven.setMaterial("ceramic");
    oven.setCapacity(60);
    oven.setWidth(70.0);
    oven.setHeight(50.0);
    oven.setDepth(60.0);
    oven.setTimerFunction(false);
    oven.setLightFunction(false);

    EXPECT_EQ(oven.getTemperature(), 200);
    EXPECT_EQ(oven.getMode(), "baking");
    EXPECT_EQ(oven.getCookingTime(), 30);
    EXPECT_FALSE(oven.getDoorState());
    EXPECT_TRUE(oven.getPowerState());
    EXPECT_EQ(oven.getColor(), "black");
    EXPECT_EQ(oven.getMaterial(), "ceramic");
    EXPECT_EQ(oven.getCapacity(), 60);
    EXPECT_EQ(oven.getWidth(), 70.0);
    EXPECT_EQ(oven.getHeight(), 50.0);
    EXPECT_EQ(oven.getDepth(), 60.0);
    EXPECT_FALSE(oven.hasTimerFunction());
    EXPECT_FALSE(oven.hasLightFunction());
}

TEST(OvenTest, InvalidTemperatureThrows) {
    Oven oven;
    EXPECT_THROW(oven.setTemperature(400), InvalidTemperatureException);
}

TEST(OvenTest, InvalidModeThrows) {
    Oven oven;
    EXPECT_THROW(oven.setMode("steam"), InvalidModeException);
}

TEST(OvenTest, InvalidCookingTimeThrows) {
    Oven oven;
    EXPECT_THROW(oven.setCookingTime(-5), InvalidTimeException);
}


TEST(OvenManagerTest, OpenCloseDoor) {
    Oven oven;
    OvenManager manager;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    manager.openDoor(oven);
    EXPECT_FALSE(oven.getDoorState());
    manager.closeDoor(oven);
    EXPECT_TRUE(oven.getDoorState());

    cout.rdbuf(oldCout);
}

TEST(OvenManagerTest, CleanOvenOutputsText) {
    OvenManager manager;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    manager.clean();

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_NE(output.find("cleaned"), string::npos);
}

TEST(OvenManagerTest, PreheatOvenWithPowerOffOutputsMessage) {
    Oven oven;
    OvenManager manager;

    oven.setPowerState(false);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    manager.preheat(oven, 180);

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_NE(output.find("must turn on"), string::npos);
}

TEST(OvenManagerTest, PreheatOvenWithPowerOnSetsTemperature) {
    Oven oven;
    OvenManager manager;

    oven.setPowerState(true);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    manager.preheat(oven, 180);

    cout.rdbuf(oldCout);

    EXPECT_EQ(oven.getTemperature(), 180);
    string output = buffer.str();
    EXPECT_NE(output.find("Preheating oven"), string::npos);
}


TEST(OvenManagerTest, TestHeatingOutputsText) {
    Oven oven;
    OvenManager manager;

    oven.setTemperature(150);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    manager.testHeating(oven);

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_NE(output.find("Testing heating elements"), string::npos);
}
TEST(ConsoleOvenPrinterTest, PrintOutputsAllFields) {
    Oven oven(180, "baking", 30, "BrandX", 3.0);
    oven.setDoorState(true);
    oven.setPowerState(true);
    oven.setColor("black");
    oven.setMaterial("ceramic");
    oven.setCapacity(60);
    oven.setWidth(70.0);
    oven.setHeight(50.0);
    oven.setDepth(60.0);
    oven.setTimerFunction(true);
    oven.setLightFunction(true);

    ConsoleOvenPrinter printer;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    printer.print(oven);

    cout.rdbuf(oldCout);
    string output = buffer.str();

    EXPECT_NE(output.find("Temperature: 180"), string::npos);
    EXPECT_NE(output.find("Mode: baking"), string::npos);
    EXPECT_NE(output.find("Cooking time: 30"), string::npos);
    EXPECT_NE(output.find("Power state: ON"), string::npos);
    EXPECT_NE(output.find("Door closed: Yes"), string::npos);
    EXPECT_NE(output.find("Brand: BrandX"), string::npos);
    EXPECT_NE(output.find("Power: 3"), string::npos);
    EXPECT_NE(output.find("Color: black"), string::npos);
    EXPECT_NE(output.find("Material: ceramic"), string::npos);
    EXPECT_NE(output.find("Capacity: 60"), string::npos);
    EXPECT_NE(output.find("Dimensions (WxHxD): 70"), string::npos);
    EXPECT_NE(output.find("Has timer: Yes"), string::npos);
    EXPECT_NE(output.find("Has light: Yes"), string::npos);
}

TEST(OvenTest, DoorAndPowerToggle) {
    Oven oven;
    oven.setDoorState(false);
    EXPECT_FALSE(oven.getDoorState());
    oven.setDoorState(true);
    EXPECT_TRUE(oven.getDoorState());

    oven.setPowerState(true);
    EXPECT_TRUE(oven.getPowerState());
    oven.setPowerState(false);
    EXPECT_FALSE(oven.getPowerState());
}

TEST(OvenTest, TimerAndLightToggle) {
    Oven oven;
    oven.setTimerFunction(false);
    EXPECT_FALSE(oven.hasTimerFunction());
    oven.setTimerFunction(true);
    EXPECT_TRUE(oven.hasTimerFunction());

    oven.setLightFunction(false);
    EXPECT_FALSE(oven.hasLightFunction());
    oven.setLightFunction(true);
    EXPECT_TRUE(oven.hasLightFunction());
}

TEST(OvenTest, SetColorAndMaterial) {
    Oven oven;
    oven.setColor("red");
    oven.setMaterial("iron");
    EXPECT_EQ(oven.getColor(), "red");
    EXPECT_EQ(oven.getMaterial(), "iron");
}

TEST(OvenTest, SetCapacityAndDimensions) {
    Oven oven;
    oven.setCapacity(100);
    oven.setWidth(80.0);
    oven.setHeight(60.0);
    oven.setDepth(70.0);

    EXPECT_EQ(oven.getCapacity(), 100);
    EXPECT_EQ(oven.getWidth(), 80.0);
    EXPECT_EQ(oven.getHeight(), 60.0);
    EXPECT_EQ(oven.getDepth(), 70.0);
}

TEST(OvenManagerTest, StartCookingThrowsIfNotAllParamsSet) {
    Oven oven;
    OvenManager manager;

    EXPECT_THROW(manager.startCooking(oven), OvenException);

    oven.setPowerState(true);
    oven.setTemperature(180);
    EXPECT_THROW(manager.startCooking(oven), OvenException);
}

TEST(OvenManagerTest, PreheatSetsTemperatureCorrectly) {
    Oven oven;
    OvenManager manager;
    oven.setPowerState(true);

    manager.preheat(oven, 220);
    EXPECT_EQ(oven.getTemperature(), 220);
}