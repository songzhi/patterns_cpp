#include <memory>

using std::unique_ptr;
using std::make_unique;


class Car {
public:
    int seats = 0;
    bool has_gps = false;

    void drive() {}
};


class CarBuilder {
    Car *car = new Car();
public:
    CarBuilder *reset() {
        car = new Car();
        return this;
    }

    CarBuilder *setSeats(int seats) {
        car->seats = seats;
        return this;
    }

    CarBuilder *setGPS() {
        car->has_gps = true;
        return this;
    }

    Car *getProduct() {
        return car;
    }
};

int main() {
    auto builder = make_unique<CarBuilder>();
    auto car = unique_ptr<Car>(builder->setGPS()->setSeats(1)->getProduct());
    car->drive();
}
