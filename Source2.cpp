#include "Header2.h"
#include <iostream>
#include <memory>
#include <conio.h>

void addRoomManually(Hotel& hotel) {
    int id;
    double price;
    int strategyChoice;

    std::cout << "������� � �������: ";
    std::cin >> id;

    std::cout << "������� ��������� �������: ";
    std::cin >> price;
    if (price < 0) {
        std::cerr << "������: ��������� ������ �� ����� ���� �������������..\n";
        return;
    }
    if (price > 250000) {
        std::cerr << "������: ��������� ������� �� ����� ���� ������ 250,000 ������.\n";
        return;
    }


    std::cout << "�������� ���������:\n1. ������ ���������\n2. ������\n";

    std::cout << "��� �����: ";

    // ��������� ������ � ������� _getch()
    char vibor = _getch();
    std::cout << vibor << std::endl; // �������� ��������� ������ ��� �������� �����
    
    if (vibor == '1') {
        strategyChoice = 1;
    }
    else if (vibor == '2') {
        strategyChoice = 2;
    }
    else {
        std::cerr << "�������� �����. ���������� �����.\n";
        return;
    }

    //std::cin >> strategyChoice;

    std::unique_ptr<IPriceStrategy> strategy;
    if (strategyChoice == 1) {
        strategy = std::make_unique<FullPriceStrategy>();
    }
    else if (strategyChoice == 2) {
        double discount;
        std::cout << "������� ������ (%): ";
        std::cin >> discount;
        strategy = std::make_unique<DiscountPriceStrategy>(discount);
    }
    else {
        std::cerr << "�������� �����. ���������� �����.\n";
        return;
    }

    try {
        hotel.addRoom(std::make_unique<Room>(id, price, std::move(strategy)));
        std::cout << "������� ������� ���������!\n";
    }
    catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << std::endl;
    }
}
