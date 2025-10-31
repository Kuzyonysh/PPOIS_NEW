#include "gtest/gtest.h"
#include "D:\Projects\Cookery\Cookery\Pan.h"
#include "D:\Projects\Cookery\Cookery\ConsolePanPrinter.h"
#include "D:\Projects\Cookery\Cookery\PanManager.h"
#include <sstream>
#include <iostream>

using namespace std;



TEST(PanTest, ConstructorSetsInitialValues) {
    Pan pan("iron", 25, "clean", 5.5, true, 25.0, 1.5, "BrandX");

    EXPECT_EQ(pan.getMaterial(), "iron");
    EXPECT_EQ(pan.getDiameter(), 25);
    EXPECT_EQ(pan.getState(), "clean");
    EXPECT_EQ(pan.getDepth(), 5.5);
    EXPECT_TRUE(pan.getHasLid());
    EXPECT_EQ(pan.getTemperature(), 25.0);
    EXPECT_EQ(pan.getWeight(), 1.5);
    EXPECT_EQ(pan.getBrand(), "BrandX");
}

TEST(PanTest, SetMaterialAndBrand) {
    Pan pan;
    pan.setMaterial("copper");
    pan.setBrand("SuperPan");
    EXPECT_EQ(pan.getMaterial(), "copper");
    EXPECT_EQ(pan.getBrand(), "SuperPan");
}

TEST(PanTest, SetDepthAndWeight) {
    Pan pan;
    pan.setDepth(6.5);
    pan.setWeight(2.0);
    EXPECT_EQ(pan.getDepth(), 6.5);
    EXPECT_EQ(pan.getWeight(), 2.0);
}

TEST(PanTest, SetDiameterValid) {
    Pan pan;
    pan.setDiameter(30);
    EXPECT_EQ(pan.getDiameter(), 30);
}

TEST(PanTest, SetDiameterInvalidThrows) {
    Pan pan;
    EXPECT_THROW(pan.setDiameter(5), InvalidDiameterException);
    EXPECT_THROW(pan.setDiameter(55), InvalidDiameterException);
}

TEST(PanTest, SetTemperatureValid) {
    Pan pan;
    pan.setTemperature(200);
    EXPECT_EQ(pan.getTemperature(), 200);
}

TEST(PanTest, SetTemperatureInvalidThrows) {
    Pan pan;
    EXPECT_THROW(pan.setTemperature(-10), InvalidTemperatureException);
    EXPECT_THROW(pan.setTemperature(500), InvalidTemperatureException);
}

TEST(PanTest, SetStateAndHasLid) {
    Pan pan;
    pan.setState("use");
    pan.setHasLid(false);
    EXPECT_EQ(pan.getState(), "use");
    EXPECT_FALSE(pan.getHasLid());
}



TEST(PanHeatingManagerTest, HeatUpValid) {
    Pan pan;
    PanHeatingManager manager;

    manager.heatUp(pan, 180);
    EXPECT_EQ(pan.getTemperature(), 180);
    EXPECT_EQ(pan.getState(), "use");
}

TEST(PanHeatingManagerTest, HeatUpTooHighThrows) {
    Pan pan;
    PanHeatingManager manager;
    EXPECT_THROW(manager.heatUp(pan, 450), InvalidTemperatureException);
}

TEST(PanHeatingManagerTest, CoolDownSetsRoomTemperature) {
    Pan pan;
    PanHeatingManager manager;
    pan.setTemperature(150);
    manager.coolDown(pan);
    EXPECT_EQ(pan.getTemperature(), 25);
}

TEST(PanHeatingManagerTest, CheckReadyOutputsCorrectly) {
    Pan pan;
    PanHeatingManager manager;
    pan.setTemperature(200);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    manager.checkReady(pan);
    cout.rdbuf(oldCout);

    EXPECT_NE(buffer.str().find("hot and ready"), string::npos);
}


TEST(PanCareManagerTest, CleanResetsStateAndTemperature) {
    Pan pan("steel", 20, "use", 5.0, true, 150.0);
    PanCareManager manager;

    manager.clean(pan);
    EXPECT_EQ(pan.getState(), "clean");
    EXPECT_EQ(pan.getTemperature(), 25);
}

TEST(PanCareManagerTest, InspectOutputsCorrectText) {
    Pan pan("iron", 25, "clean", 5.0, true, 25.0, 1.5, "BrandX");
    PanCareManager manager;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    manager.inspect(pan);
    cout.rdbuf(oldCout);

    string output = buffer.str();
    EXPECT_NE(output.find("Inspecting BrandX pan"), string::npos);
    EXPECT_NE(output.find("State: clean"), string::npos);
}


TEST(PanStorageManagerTest, CoverWithLid) {
    Pan pan("steel", 20, "clean", 5.0, true);
    PanStorageManager manager;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    manager.cover(pan);
    cout.rdbuf(oldCout);

    string output = buffer.str();
    EXPECT_NE(output.find("Pan is now covered"), string::npos);
}

TEST(PanStorageManagerTest, CoverWithoutLid) {
    Pan pan("steel", 20, "clean", 5.0, false);
    PanStorageManager manager;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    manager.cover(pan);
    cout.rdbuf(oldCout);

    string output = buffer.str();
    EXPECT_NE(output.find("doesn’t have a lid"), string::npos);
}

TEST(PanStorageManagerTest, ReplaceLidAddsAndRemoves) {
    Pan pan("steel", 20, "clean", 5.0, false);
    PanStorageManager manager;

    manager.replaceLid(pan, true);
    EXPECT_TRUE(pan.getHasLid());
    manager.replaceLid(pan, false);
    EXPECT_FALSE(pan.getHasLid());
}

TEST(PanStorageManagerTest, StoreCleanPanOutputsStored) {
    Pan pan("steel", 20, "clean", 5.0, true);
    PanStorageManager manager;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    manager.store(pan);
    cout.rdbuf(oldCout);

    EXPECT_NE(buffer.str().find("Pan stored in cabinet"), string::npos);
}

TEST(PanStorageManagerTest, StoreDirtyPanPromptsCleaning) {
    Pan pan("steel", 20, "use", 5.0, true);
    PanStorageManager manager;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    manager.store(pan);
    cout.rdbuf(oldCout);

    EXPECT_NE(buffer.str().find("Please clean the pan"), string::npos);
}


TEST(ConsolePanPrinterTest, PrintOutputsCorrectText) {
    Pan pan("steel", 25, "use", 5.0, true, 180.0, 1.5, "BrandX");
    ConsolePanPrinter printer;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    printer.print(pan);
    cout.rdbuf(oldCout);

    string output = buffer.str();
    EXPECT_NE(output.find("Material: steel"), string::npos);
    EXPECT_NE(output.find("Diameter: 25"), string::npos);
    EXPECT_NE(output.find("State: use"), string::npos);
    EXPECT_NE(output.find("Depth: 5"), string::npos);
    EXPECT_NE(output.find("Weight: 1.5"), string::npos);
    EXPECT_NE(output.find("Temperature: 180"), string::npos);
    EXPECT_NE(output.find("Has Lid: Yes"), string::npos);
}
