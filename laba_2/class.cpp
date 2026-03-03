#include <iostream> 
#include <string> 

using namespace std;

class Device {
 public:
  Device(): brand_("unknown"), model_(0000), color_("unknown") {
    cout << "Device is created! (no param)" << endl;
  }

  Device(string brand, int model, string color): 
         brand_(brand), model_(model), color_(color) {
    cout << "Device is created (with param)" << endl;
  }

  Device(const Device& device) {
    brand_ = device.brand_;
    model_ = device.model_;
    color_ = device.color_;
    cout << "Device is created (copy)" << endl;
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

  void Print() {
    cout << "Device: brand " << brand_ << ", model " << model_ << ", color " << color_ << endl;
  }

  void SetColor(string color) {
    color_ = color;
  }

 private:
  string brand_;
  int model_;
  string color_;
};


class SmartPhone: public Device {
 public:
  SmartPhone(): Device(), SIMCard_(false), camMP_(0) {
    cout << "Smartphone is created (no param)" << endl;
  }

  SmartPhone(string brand, int model, string color, bool SIMCard, int camMP): 
             Device(brand, model, color), SIMCard_(SIMCard), camMP_(camMP) {
    cout << "Smartphone is created, (with param)" << endl;
  }

  SmartPhone(const SmartPhone& smartPhone): Device(smartPhone) {
    SIMCard_ = smartPhone.SIMCard_;
    camMP_ = smartPhone.camMP_;

    cout << "Smartphone is created, (copy)" << endl;
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

  void Call() {
    cout << "Calling my bestie Stacey on the phone" << endl;
  }

 private:
  bool SIMCard_;
  int camMP_;
};


class Tablet: public SmartPhone {
 public:
  Tablet(): SmartPhone(), has_keyboard_(false) {
    cout << "Tablet is created (no param)" << endl;
  }

  Tablet(string brand, int model, string color, bool SIMCard, int camMP, bool has_keyboard): 
         SmartPhone(brand, model, color, SIMCard, camMP), 
         has_keyboard_(has_keyboard) {
    cout << "Tablet is created (with param)" << endl;
  }

  Tablet(const Tablet& tablet): SmartPhone(tablet) {
    has_keyboard_ = tablet.has_keyboard_;

    cout << "Tablet is created (copy)" << endl;
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

  void Call() {
    cout << "Calling my bestie Stacey on the tablet" << endl;
  }

  void Draw();

 private:
  bool has_keyboard_;
};

void Tablet::Draw() {
  cout << "Drawing a portrait of my crush, the captain of the football team, Brandon.";
}

class CloudStorage {


 private:
  SmartPhone *ptr_smph;
  Tablet *ptr_tblt;
};

class Parent {
 public:
  Parent() {
    cout << "Parent is created " << endl;
  }

  ~Parent() {
    cout << "Parent is destroyed " << endl;
  }

  int public_value = 1;

 protected:
  int protected_value = 2;

 private:
  int private_value = 3;
};

class Child: public Parent {
 public:
  Child(): p() {
    cout << "Child is created" << endl;

    cout << "Create pointer: ";
    ptr_parent = new Parent;

    cout << "Create object: ";
    // Parent p;
  }


  ~Child() {
    cout << "Kill pointer: ";
    delete ptr_parent;

    cout << "Child is died" << endl;
  }

  void Check() {
    this->public_value += 1;
    this->protected_value += 1;
    // this->private_value += 1;
  }


 private:
  Parent *ptr_parent;
  Parent p;
};


class A {
public:
  A() {
    cout << "I am created!\n";
  }
  ~A() {
    cout << "I am dyed!\n";
  }
};

class B: public A {};