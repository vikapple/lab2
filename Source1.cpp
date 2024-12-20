#include "Header1.h"

// FullPriceStrategy
double FullPriceStrategy::getPrice(double basePrice) const {
    return basePrice;

}

// DiscountPriceStrategy
DiscountPriceStrategy::DiscountPriceStrategy(double discountPercent) : discount(discountPercent) {
    if (discount < 0 || discount > 100) {
        throw std::invalid_argument("—кидка должна быть от 0% до 100%");
    }
}

double DiscountPriceStrategy::getPrice(double basePrice) const {
    return basePrice * (1 - discount / 100.0);
}

// Room
Room::Room(int roomId, double price, std::unique_ptr<IPriceStrategy> priceStrategy)
    : id(roomId), basePrice(price), strategy(std::move(priceStrategy)) {
    if (price < 0) {
        throw std::invalid_argument("—тоимость номера не может быть отрицательной.");
    }
    /*if (price > 250000) {
        throw std::invalid_argument("—тоимость номера не может быть больше 250,000 рублей.");
    }*/
}

double Room::getPrice() const {
    return strategy->getPrice(basePrice);
}

void Room::setStrategy(std::unique_ptr<IPriceStrategy> newStrategy) {
    strategy = std::move(newStrategy);
}

int Room::getId() const {
    return id;
}

// Hotel
void Hotel::addRoom(std::unique_ptr<Room> room) {
    for (const auto& r : rooms) {
        if (r->getId() == room->getId()) {
            throw std::runtime_error(" омната с таким ID уже существует.");
        }
    }
    rooms.push_back(std::move(room));
}

double Hotel::calculateAverageCost() const {
    if (rooms.empty()) {
        throw std::runtime_error("Ќет свободных номеров дл€ расчета средней стоимости.");
    }
    double totalCost = 0;
    for (const auto& room : rooms) {
        totalCost += room->getPrice();
    }
    return totalCost / rooms.size();
}
