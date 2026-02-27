#include <iostream> 
#include <string>

using namespace std;

class Device {
 public:
  enum Color {unknown, white, grey, black, blue, pink};
  enum Brand {noName, Apple, Samsung, Nokia, Xiomi};
  enum Software {noSoftware, IOS, Android, Huawei};

  Device(): brand_(noName), model_(0000), color_(unknown), powerConsumption_(0), weight_(0), software_(noSoftware) {
    cout << "Устройство создалось" << endl;
  }

  Device(Brand brand, int model, Color color, int powerConsumption, int weight, Software software): 
         brand_(brand), model_(model), color_(color), powerConsumption_(powerConsumption), weight_(weight), software_(software) {
    cout << "Устройство создалось" << endl;
  }

  Device(const Device& device) {
    brand_ = device.brand_;
    model_ = device.model_;
    color_ = device.color_;
    powerConsumption_ = device.powerConsumption_;
    weight_ = device.weight_;
    software_ = device.software_;

    cout << "Устройство создалось" << endl;
  }

  ~Device() {
    cout << "Устройство устранилось. Пока!" << endl;
  }

  virtual void TurnOn() {
    cout << "Устройство включено!" << endl;
  }

  virtual void TurnOff() {
    cout << "Устройство выключено!" << endl;
  }

 private:
  Brand brand_;
  int model_;
  Color color_;
  int powerConsumption_;
  int weight_;
  Software software_;
};


class SmartPhone: public Device {
 public:
  SmartPhone(): Device(), SIMCard_(false), camMP_(0) {
    cout << "Смартфон создался" << endl;
  }

  SmartPhone(Brand brand, int model, Color color, int powerConsumption, int weight, Software software, bool SIMCard, int camMP): 
             Device(brand, model, color, powerConsumption, weight, software), SIMCard_(SIMCard), camMP_(camMP) {
    cout << "Смартфон создался" << endl;
  }

  SmartPhone(const SmartPhone& smartPhone): Device(smartPhone) {
    SIMCard_ = smartPhone.SIMCard_;
    camMP_ = smartPhone.camMP_;

    cout << "Смартфон создался" << endl;
  }

  ~SmartPhone() {
    cout << "Смартфон устранился. Пока!" << endl;
  }

  void TurnOn() override {
    cout << "Смартфон включен!" << endl;
  }

  void TurnOff() override {
    cout << "Смартфон выключен!" << endl;
  }

  virtual void Call() {
    cout << "Звоню своей подружке Стейсииииии через телефон" << endl;
  }

 private:
  bool SIMCard_;
  int camMP_;
};


class Tablet: public SmartPhone {
 public:
  Tablet(): SmartPhone(), has_keyboard_(false) {
    cout << "Планшет создался" << endl;
  }

  Tablet(Brand brand, int model, Color color, int powerConsumption, int weight, 
         Software software, bool SIMCard, int camMP, bool has_keyboard): 
         SmartPhone(brand, model, color, powerConsumption, weight, software, SIMCard, camMP), 
         has_keyboard_(has_keyboard) {
    cout << "Планшет создался" << endl;
  }

  Tablet(const Tablet& tablet): SmartPhone(tablet) {
    has_keyboard_ = tablet.has_keyboard_;

    cout << "Планшет создался" << endl;
  }

  ~Tablet() {
    cout << "Планшет устранился. Пока!" << endl;
  }

  void TurnOn() override {
    cout << "Планшет включен!" << endl;
  }

  void TurnOff() override {
    cout << "Планшет выключен!" << endl;
  }

  void Call() override {
    cout << "Звоню своей подружке Стейсииииии через планшет" << endl;
  }

  void Draw () {
    cout << "Рисую портрет своего краша капитана футбольной команды Брендона";
  }

 private:
  bool has_keyboard_;
};