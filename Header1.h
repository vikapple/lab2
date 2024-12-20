
#ifndef CLASS_H
#define CLASS_H

#include <memory>
#include <vector>
#include <stdexcept>
#include <msclr/marshal_cppstd.h>

// ��������� ��� ��������� ���������������
class IPriceStrategy {
public:
    virtual double getPrice(double basePrice) const = 0;
    virtual ~IPriceStrategy() = default;
};

// ���������� ������ ���������
class FullPriceStrategy : public IPriceStrategy {
public:
    double getPrice(double basePrice) const override;
};

// ���������� ��������� �� �������
class DiscountPriceStrategy : public IPriceStrategy {
private:
    double discount; // � %
public:
    explicit DiscountPriceStrategy(double discountPercent);
    double getPrice(double basePrice) const override;
};

// ����� Room
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

// ����� Hotel
class Hotel {
private:
    std::vector<std::unique_ptr<Room>> rooms;
public:
    void addRoom(std::unique_ptr<Room> room);
    double calculateAverageCost() const;
};

#endif // CLASS_H

