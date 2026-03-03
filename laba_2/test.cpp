#include "class.cpp" 

void TestAccesModifiers() {
    Parent p;
    p.public_value += 1;
    // p.protected_value += 1;
    // p.private_value += 1;

    Child c;
    c.public_value += 1;
    // c.protected_value += 1;
    // c.private_value += 1;
}

void TestStaticDynamic() {
    Device d1;
    Device *ptr_d2 = new Device();
    
    // delete ptr_d2;
}

void TestCreateObjects() {
    Device d1;
    Device d2("Apple", 3000, "black");
    Device d3(d2);

    SmartPhone sm;
}

void TestObjectAndPointer() {
    Child a;
}

void TestObjectCopy() {
    Device d1("Apple", 3000, "black");
    Device d2 = d1;

    d1.Print();
    d2.Print();

    d1.SetColor("white");
    
    d1.Print();
    d2.Print();
}

void TestPointerCopy() {
    Device *d1 = new Device("Apple", 3000, "black");
    Device *d2 = d1;

    d1->Print();
    d2->Print();

    d1->SetColor("white");
    
    d1->Print();
    d2->Print();
}

void TestDiffTypes() {
    Device *d = new Device();
    Device *smAsDevice = new SmartPhone();
    SmartPhone *sm = new SmartPhone();

    d->TurnOn();
    smAsDevice->TurnOn();
    sm->TurnOn();

    // d->Call();
    // smAsDevice->Call();
    sm->Call();

    delete d;
    delete smAsDevice;
    delete sm;
}

void Test() {
    // A a;
    B b;
}


int main() {
    // TestAccesModifiers();
    // TestStaticDynamic();
    // TestCreateObjects();
    // TestObjectAndPointer();
    // TestObjectCopy();
    // TestPointerCopy();
    // TestDiffTypes();
    Test();
}