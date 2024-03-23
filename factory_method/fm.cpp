#include <iostream>

class IProduction{
    public:
        virtual void release() = 0;
};

class Car : public IProduction{
    public:
        void release() override{
            std::cout << "Выпущен легковой автомобиль" << "std::endl";
        }
};

class Truck : public IProduction{
    public:
        void release() override{
            std::cout << "Выпущен грузовой автомобиль" << std::endl;
        }
};

class IWorkShop{
    public:
        virtual IProduction* create() = 0;
};

class CarWorkShop : public IWorkShop{
    public:
        IProduction* create() override{
            return new Car();
        }
};

class TruckWorkShop : public IWorkShop{
    public:
        IProduction* create() override{
            return new Truck();
        }
};

int main(){

    IWorkShop* creator = new CarWorkShop();
    IProduction* car = creator->create();

    creator = new TruckWorkShop();
    IProduction * truck = creator->create();

    car->release();
    truck->release();

    return 0;
}