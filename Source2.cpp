#include "Header2.h"
#include <iostream>
#include <memory>
#include <conio.h>

void addRoomManually(Hotel& hotel) {
    int id;
    double price;
    int strategyChoice;

    std::cout << "Введите № комнаты: ";
    std::cin >> id;

    std::cout << "Введите стоимость комнаты: ";
    std::cin >> price;
    if (price < 0) {
        std::cerr << "Ошибка: Стоимость номера не может быть отрицательной..\n";
        return;
    }
    if (price > 250000) {
        std::cerr << "Ошибка: Стоимость комнаты не может быть больше 250,000 рублей.\n";
        return;
    }


    std::cout << "Выберите стратегию:\n1. Полная стоимость\n2. Скидка\n";

    std::cout << "Ваш выбор: ";

    // Получение выбора с помощью _getch()
    char vibor = _getch();
    std::cout << vibor << std::endl; // Печатаем выбранный символ для обратной связи
    
    if (vibor == '1') {
        strategyChoice = 1;
    }
    else if (vibor == '2') {
        strategyChoice = 2;
    }
    else {
        std::cerr << "Неверный выбор. Попробуйте снова.\n";
        return;
    }

    //std::cin >> strategyChoice;

    std::unique_ptr<IPriceStrategy> strategy;
    if (strategyChoice == 1) {
        strategy = std::make_unique<FullPriceStrategy>();
    }
    else if (strategyChoice == 2) {
        double discount;
        std::cout << "Введите скидку (%): ";
        std::cin >> discount;
        strategy = std::make_unique<DiscountPriceStrategy>(discount);
    }
    else {
        std::cerr << "Неверный выбор. Попробуйте снова.\n";
        return;
    }

    try {
        hotel.addRoom(std::make_unique<Room>(id, price, std::move(strategy)));
        std::cout << "Комната успешно добавлена!\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}
