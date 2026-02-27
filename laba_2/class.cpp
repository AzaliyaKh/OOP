#include <iostream> 

using namespace std;

class Device {
 public:
  enum Color {unknown, white, grey, black, blue, pink};
  enum Brand {noName, Apple, Samsung, Nokia, Xiomi};
  enum Software {noSoftware, IOS, Android, Huawei};

  Device(): brand_(noName), model_(0000), color_(unknown) {
    cout << "Device is created" << endl;
  }

  Device(Brand brand, int model, Color color): 
         brand_(brand), model_(model), color_(color) {
    cout << "Device is created" << endl;
  }

  Device(const Device& device) {
    brand_ = device.brand_;
    model_ = device.model_;
    color_ = device.color_;
    cout << "Device is created" << endl;
  }

  ~Device() {
    cout << "Device destroyed!" << endl;
  }

  virtual void TurnOn() {
    cout << "Device is turn on!" << endl;
  }

  virtual void TurnOff() {
    cout << "Device is turn off!" << endl;
  }

 private:
  Brand brand_;
  int model_;
  Color color_;
};


class SmartPhone: public Device {
 public:
  SmartPhone(): Device(), SIMCard_(false), camMP_(0) {
    cout << "Smartphone is created" << endl;
  }

  SmartPhone(Brand brand, int model, Color color, bool SIMCard, int camMP): 
             Device(brand, model, color), SIMCard_(SIMCard), camMP_(camMP) {
    cout << "Smartphone is created" << endl;
  }

  SmartPhone(const SmartPhone& smartPhone): Device(smartPhone) {
    SIMCard_ = smartPhone.SIMCard_;
    camMP_ = smartPhone.camMP_;

    cout << "Smartphone is created" << endl;
  }

  ~SmartPhone() {
    cout << "Smartphone is destroyed" << endl;
  }

  void TurnOn() override {
    cout << "Smartphone is turn on!" << endl;
  }

  void TurnOff() override {
    cout << "Smartphone is turn off!" << endl;
  }

  virtual void Call() {
    cout << "Calling my bestie Stacey on the phone" << endl;
  }

 private:
  bool SIMCard_;
  int camMP_;
};


class Tablet: public SmartPhone {
 public:
  Tablet(): SmartPhone(), has_keyboard_(false) {
    cout << "Tablet is created" << endl;
  }

  Tablet(Brand brand, int model, Color color, bool SIMCard, int camMP, bool has_keyboard): 
         SmartPhone(brand, model, color, SIMCard, camMP), 
         has_keyboard_(has_keyboard) {
    cout << "Tablet is created" << endl;
  }

  Tablet(const Tablet& tablet): SmartPhone(tablet) {
    has_keyboard_ = tablet.has_keyboard_;

    cout << "Tablet is created" << endl;
  }

  ~Tablet() {
    cout << "Tablet is destroyed" << endl;
  }

  void TurnOn() override {
    cout << "Tablet is turn on!" << endl;
  }

  void TurnOff() override {
    cout << "Tablet is turn off!" << endl;
  }

  void Call() override {
    cout << "Calling my bestie Stacey on the tablet" << endl;
  }

  void Draw () {
    cout << "Drawing a portrait of my crush, the captain of the football team, Brandon.";
  }

 private:
  bool has_keyboard_;
};

class CloudStorage {


 private:
  SmartPhone *ptr_smph;
  Tablet *ptr_tblt;
};