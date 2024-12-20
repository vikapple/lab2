//#pragma once
//
//#include "Header1.h"
//#include "Header2.h"
//#include <msclr/marshal_cppstd.h>
//#include "AddRoomForm.h"
//
//namespace HotelManager {
//
//    using namespace System;
//    using namespace System::Windows::Forms;
//    using namespace System::Drawing;
//
//    public ref class MainForm : public Form {
//    private:
//        Hotel* hotel; // ������ �����
//        TextBox^ roomIdBox;
//        TextBox^ roomPriceBox;
//        TextBox^ discountBox;
//        Label^ outputLabel;
//
//    public:
//        MainForm() {
//            this->Text = "���������� ������";
//            this->Size = System::Drawing::Size(500, 400);
//
//            // ������������� ������� Hotel
//            hotel = new Hotel();
//
//            // �������� ����������
//            Label^ label1 = gcnew Label();
//            label1->Text = "ID �������:";
//            label1->Location = Point(10, 10);
//            this->Controls->Add(label1);
//
//            roomIdBox = gcnew TextBox();
//            roomIdBox->Location = Point(150, 10);
//            this->Controls->Add(roomIdBox);
//
//            Label^ label2 = gcnew Label();
//            label2->Text = "���� �������:";
//            label2->Location = Point(10, 50);
//            this->Controls->Add(label2);
//
//            roomPriceBox = gcnew TextBox();
//            roomPriceBox->Location = Point(150, 50);
//            this->Controls->Add(roomPriceBox);
//
//            Label^ label3 = gcnew Label();
//            label3->Text = "������ (%):";
//            label3->Location = Point(10, 90);
//            this->Controls->Add(label3);
//
//            discountBox = gcnew TextBox();
//            discountBox->Location = Point(150, 90);
//            this->Controls->Add(discountBox);
//
//            Button^ addRoomButton = gcnew Button();
//            addRoomButton->Text = "�������� �������";
//            addRoomButton->Location = Point(10, 130);
//            addRoomButton->Click += gcnew EventHandler(this, &MainForm::AddRoomButton_Click);
//            this->Controls->Add(addRoomButton);
//
//            Button^ calcAverageButton = gcnew Button();
//            calcAverageButton->Text = "���������� ������� ���������";
//            calcAverageButton->Location = Point(10, 170);
//            calcAverageButton->Click += gcnew EventHandler(this, &MainForm::CalcAverageButton_Click);
//            this->Controls->Add(calcAverageButton);
//
//            outputLabel = gcnew Label();
//            outputLabel->Text = "";
//            outputLabel->AutoSize = true;
//            outputLabel->Location = Point(10, 210);
//            this->Controls->Add(outputLabel);
//        }
//
//        ~MainForm() {
//            delete hotel;
//        }
//
//    private:
//        void AddRoomButton_Click(Object^ sender, EventArgs^ e) {
//            try {
//                int id = Int32::Parse(roomIdBox->Text);
//                double price = Double::Parse(roomPriceBox->Text);
//                double discount = Double::Parse(discountBox->Text);
//
//                std::unique_ptr<IPriceStrategy> strategy;
//
//                if (discount > 0) {
//                    strategy = std::make_unique<DiscountPriceStrategy>(discount);
//                }
//                else {
//                    strategy = std::make_unique<FullPriceStrategy>();
//                }
//
//                auto room = std::make_unique<Room>(id, price, std::move(strategy));
//                hotel->addRoom(std::move(room));
//
//                outputLabel->Text = "������� ��������� �������!";
//            }
//            catch (const std::exception& ex) {
//                outputLabel->Text = "������: " + gcnew String(ex.what());
//            }
//            catch (Exception^ ex) {
//                outputLabel->Text = "������: " + ex->Message;
//            }
//        }
//
//        void CalcAverageButton_Click(Object^ sender, EventArgs^ e) {
//            try {
//                double average = hotel->calculateAverageCost();
//                outputLabel->Text = "������� ���������: " + average.ToString("F2");
//            }
//            catch (const std::exception& ex) {
//                outputLabel->Text = "������: " + gcnew String(ex.what());
//            }
//        }
//    };
//}

 
//2 �������
//#pragma once
//
//#include "AddRoomForm.h"
//#include "Header1.h"
//#include "Header2.h"
//#include <msclr/marshal_cppstd.h>
//
//namespace HotelManager {
//
//    using namespace System;
//    using namespace System::Windows::Forms;
//    using namespace System::Drawing;
//    using namespace System::Collections::Generic;
//
//    public ref class MyForm : public Form {
//    private:
//        Hotel* hotel; // ������ �����
//        ListBox^ roomListBox; // ��� ����������� ������ ������
//        Label^ outputLabel;
//
//    public:
//        MyForm() {
//            this->Text = "���������� ������";
//            this->Size = System::Drawing::Size(500, 400);
//
//            // ������������� ������� Hotel
//            hotel = new Hotel();
//
//            Button^ addRoomButton = gcnew Button();
//            addRoomButton->Text = "�������� �������";
//            addRoomButton->Location = Point(10, 10);
//            addRoomButton->Click += gcnew EventHandler(this, &MyForm::AddRoomButton_Click);
//            this->Controls->Add(addRoomButton);
//
//            Button^ calcAverageButton = gcnew Button();
//            calcAverageButton->Text = "���������� ���������";
//            calcAverageButton->Location = Point(150, 10);
//            calcAverageButton->Click += gcnew EventHandler(this, &MyForm::CalcAverageButton_Click);
//            this->Controls->Add(calcAverageButton);
//
//            roomListBox = gcnew ListBox();
//            roomListBox->Location = Point(10, 50);
//            roomListBox->Size = System::Drawing::Size(460, 200);
//            this->Controls->Add(roomListBox);
//
//            outputLabel = gcnew Label();
//            outputLabel->Text = "";
//            outputLabel->AutoSize = true;
//            outputLabel->Location = Point(10, 270);
//            this->Controls->Add(outputLabel);
//        }
//
//        ~MyForm() {
//            delete hotel;
//        }
//
//    private:
//        void AddRoomButton_Click(Object^ sender, EventArgs^ e) {
//            AddRoomForm^ addRoomForm = gcnew AddRoomForm(hotel, roomListBox);
//            addRoomForm->ShowDialog();
//        }
//
//        void CalcAverageButton_Click(Object^ sender, EventArgs^ e) {
//            try {
//                double average = hotel->calculateAverageCost();
//                outputLabel->Text = "������� ���������: " + average.ToString("F2");
//            }
//            catch (const std::exception& ex) {
//                outputLabel->Text = "������: " + gcnew String(ex.what());
//            }
//        }
//    };
//}
//����� 2 ��������


#pragma once

#include "AddRoomForm.h"
#include "Header1.h"
#include "Header2.h"
#include <msclr/marshal_cppstd.h>
#include <vector>
#include <string>

namespace HotelManager {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Collections::Generic;

    public ref class MainForm : public Form {
    private:
        Hotel* hotel; // �������� ������ �����
        ListBox^ roomListBox; // ��� ����������� ������ ������
        Label^ outputLabel;

    public:
        MainForm() {
            this->Text = "���������� ������";
            this->Size = System::Drawing::Size(600, 400);

            // ������������� ������� Hotel
            hotel = new Hotel();

            // ������ ��� ������ ������
            GroupBox^ roomGroup = gcnew GroupBox();
            roomGroup->Text = "������ ������";
            roomGroup->Size = System::Drawing::Size(300, 360);
            roomGroup->Location = Point(10, 10);
            this->Controls->Add(roomGroup);

            roomListBox = gcnew ListBox();
            roomListBox->Size = System::Drawing::Size(280, 320);
            roomListBox->Location = Point(10, 20);
            roomGroup->Controls->Add(roomListBox);

            // ������ ��� ��������
            GroupBox^ actionGroup = gcnew GroupBox();
            actionGroup->Text = "��������";
            actionGroup->Size = System::Drawing::Size(250, 360);
            actionGroup->Location = Point(320, 10);
            this->Controls->Add(actionGroup);

            Button^ addRoomButton = gcnew Button();
            addRoomButton->Text = "�������� �������";
            addRoomButton->Size = System::Drawing::Size(200, 40);
            addRoomButton->Location = Point(20, 30);
            addRoomButton->Click += gcnew EventHandler(this, &MainForm::AddRoomButton_Click);
            actionGroup->Controls->Add(addRoomButton);

            Button^ calcAverageButton = gcnew Button();
            calcAverageButton->Text = "���������� ���������";
            calcAverageButton->Size = System::Drawing::Size(200, 40);
            calcAverageButton->Location = Point(20, 90);
            calcAverageButton->Click += gcnew EventHandler(this, &MainForm::CalcAverageButton_Click);
            actionGroup->Controls->Add(calcAverageButton);

            /*Button^ saveButton = gcnew Button();
            saveButton->Text = "��������� � ����";
            saveButton->Size = System::Drawing::Size(200, 40);
            saveButton->Location = Point(20, 150);
            saveButton->Click += gcnew EventHandler(this, &MainForm::SaveButton_Click);
            actionGroup->Controls->Add(saveButton);

            Button^ loadButton = gcnew Button();
            loadButton->Text = "��������� �� �����";
            loadButton->Size = System::Drawing::Size(200, 40);
            loadButton->Location = Point(20, 210);
            loadButton->Click += gcnew EventHandler(this, &MainForm::LoadButton_Click);
            actionGroup->Controls->Add(loadButton);*/

            /*Button^ sortButton = gcnew Button();
            sortButton->Text = "����������� �� ID";
            sortButton->Size = System::Drawing::Size(200, 40);
            sortButton->Location = Point(20, 150);
            sortButton->Click += gcnew EventHandler(this, &MainForm::SortButton_Click);
            actionGroup->Controls->Add(sortButton);*/

            outputLabel = gcnew Label();
            outputLabel->Text = "";
            outputLabel->AutoSize = true;
            outputLabel->Location = Point(20, 220);
            actionGroup->Controls->Add(outputLabel);
        }

        ~MainForm() {
            delete hotel;
        }

    private:

        void AddRoomButton_Click(Object^ sender, EventArgs^ e) {
            AddRoomForm^ addRoomForm = gcnew AddRoomForm(hotel, roomListBox);
            addRoomForm->ShowDialog();
        }

        void CalcAverageButton_Click(Object^ sender, EventArgs^ e) {
            try {
                double average = hotel->calculateAverageCost();
                outputLabel->Text = "������� ���������: " + average.ToString("F2");
            }
            catch (const std::exception& ex) {
                outputLabel->Text = "������: " + gcnew String(ex.what());
            }
        }


        //void SaveButton_Click(Object^ sender, EventArgs^ e) {
        //    try {
        //        hotel->saveToFile("hotel_rooms.txt");
        //        outputLabel->Text = "������ ������� ���������!";
        //    }
        //    catch (const std::exception& ex) {
        //        outputLabel->Text = "������: " + gcnew String(ex.what());
        //    }
        //}

        //void LoadButton_Click(Object^ sender, EventArgs^ e) {
        //    try {
        //        hotel->loadFromFile("hotel_rooms.txt");
        //        outputLabel->Text = "������ ������� ���������!";
        //        roomListBox->Items->Clear();

        //        // ��������� ������ ������
        //        for (const auto& room : hotel->getRooms()) {
        //            roomListBox->Items->Add("������� " + room->getId() + ": " + room->getPrice().ToString("F2"));
        //        }
        //    }
        //    catch (const std::exception& ex) {
        //        outputLabel->Text = "������: " + gcnew String(ex.what());
        //    }
        //}
    
        //void SortButton_Click(Object^ sender, EventArgs^ e) {
        //    try {
        //        // ����� ���������� �� ������� Hotel
        //        hotel->sortRooms();

        //        // ���������� ������ ������ � ListBox
        //        UpdateRoomList();
        //    }
        //    catch (const std::exception& ex) {
        //        outputLabel->Text = "������: " + gcnew String(ex.what());
        //    }
        //}

        //void UpdateRoomList() {
        //    roomListBox->Items->Clear();

        //    for (const auto& room : hotel->getRoomDescriptions()) {
        //        roomListBox->Items->Add(gcnew String(room.c_str()));
        //    }
        //}
    };
}
