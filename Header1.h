
#ifndef CLASS_H
#define CLASS_H

#include <memory>
#include <vector>
#include <stdexcept>
#include <msclr/marshal_cppstd.h>

// Интерфейс для стратегии ценообразования
class IPriceStrategy {
public:
    virtual double getPrice(double basePrice) const = 0;
    virtual ~IPriceStrategy() = default;
};

// Реализация полной стоимости
class FullPriceStrategy : public IPriceStrategy {
public:
    double getPrice(double basePrice) const override;
};

// Реализация стоимости со скидкой
class DiscountPriceStrategy : public IPriceStrategy {
private:
    double discount; // В %
public:
    explicit DiscountPriceStrategy(double discountPercent);
    double getPrice(double basePrice) const override;
};

// Класс Room
class Room {
private:
    int id;
    double basePrice;
    std::unique_ptr<IPriceStrategy> strategy;
public:
    Room(int roomId, double price, std::unique_ptr<IPriceStrategy> priceStrategy);
    double getPrice() const;
    void setStrategy(std::unique_ptr<IPriceStrategy> newStrategy);
    int getId() const;
};

// Класс Hotel
class Hotel {
private:
    std::vector<std::unique_ptr<Room>> rooms;
public:
    void addRoom(std::unique_ptr<Room> room);
    double calculateAverageCost() const;
};

#endif // CLASS_H

