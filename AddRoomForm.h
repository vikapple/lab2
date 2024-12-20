//#pragma once
//
//#include "Header1.h"
//#include "Header2.h"
//#include <msclr/marshal_cppstd.h>
//
//namespace HotelManager {
//	
//	using namespace System;
//	using namespace System::ComponentModel;
//	using namespace System::Collections;
//	using namespace System::Windows::Forms;
//	using namespace System::Data;
//	using namespace System::Drawing;
//
//	/// <summary>
//	/// Сводка для AddRoomForm
//	/// </summary>
//	public ref class AddRoomForm : public System::Windows::Forms::Form
//	{
//	public:
//		AddRoomForm(void)
//		{
//			InitializeComponent();
//			//
//			//TODO: добавьте код конструктора
//			//
//		}
//
//	protected:
//		/// <summary>
//		/// Освободить все используемые ресурсы.
//		/// </summary>
//		~AddRoomForm()
//		{
//			if (components)
//			{
//				delete components;
//			}
//		}
//
//	private:
//		/// <summary>
//		/// Обязательная переменная конструктора.
//		/// </summary>
//		System::ComponentModel::Container ^components;
//
//#pragma region Windows Form Designer generated code
//		/// <summary>
//		/// Требуемый метод для поддержки конструктора — не изменяйте 
//		/// содержимое этого метода с помощью редактора кода.
//		/// </summary>
//		void InitializeComponent(void)
//		{
//			this->components = gcnew System::ComponentModel::Container();
//			this->Size = System::Drawing::Size(300,300);
//			this->Text = L"AddRoomForm";
//			this->Padding = System::Windows::Forms::Padding(0);
//			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
//		}
//#pragma endregion
//	};
//}
//
//
//

#pragma once

#include "Header1.h"
#include "Header2.h"
#include <msclr/marshal_cppstd.h>

namespace HotelManager {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class AddRoomForm : public Form {
    private:
        Hotel* hotel;
        ListBox^ roomListBox;

        TextBox^ roomIdBox;
        TextBox^ roomPriceBox;
        TextBox^ discountBox;

    public:
        AddRoomForm(Hotel* hotelRef, ListBox^ listBoxRef) {
            this->hotel = hotelRef;
            this->roomListBox = listBoxRef;

            this->Text = "Добавить комнату";
            this->Size = System::Drawing::Size(400, 300);

            Label^ label1 = gcnew Label();
            label1->Text = "ID комнаты:";
            label1->Location = Point(10, 10);
            this->Controls->Add(label1);

            roomIdBox = gcnew TextBox();
            roomIdBox->Location = Point(150, 10);
            this->Controls->Add(roomIdBox);

            Label^ label2 = gcnew Label();
            label2->Text = "Цена комнаты:";
            label2->Location = Point(10, 50);
            this->Controls->Add(label2);

            roomPriceBox = gcnew TextBox();
            roomPriceBox->Location = Point(150, 50);
            this->Controls->Add(roomPriceBox);

            Label^ label3 = gcnew Label();
            label3->Text = "Скидка (%):";
            label3->Location = Point(10, 90);
            this->Controls->Add(label3);

            discountBox = gcnew TextBox();
            discountBox->Location = Point(150, 90);
            this->Controls->Add(discountBox);

            Button^ saveButton = gcnew Button();
            saveButton->Text = "Сохранить";
            saveButton->Location = Point(10, 130);
            saveButton->Click += gcnew EventHandler(this, &AddRoomForm::SaveButton_Click);
            this->Controls->Add(saveButton);

            Button^ clearButton = gcnew Button();
            clearButton->Text = "Очистить";
            clearButton->Location = Point(150, 130);
            clearButton->Click += gcnew EventHandler(this, &AddRoomForm::ClearButton_Click);
            this->Controls->Add(clearButton);
        }

    private:
        void SaveButton_Click(Object^ sender, EventArgs^ e) {
            try {
                int id = Int32::Parse(roomIdBox->Text);
                double price = Double::Parse(roomPriceBox->Text);
                double discount = Double::Parse(discountBox->Text);

                std::unique_ptr<IPriceStrategy> strategy;

                if (discount > 0) {
                    strategy = std::make_unique<DiscountPriceStrategy>(discount);
                }
                else {
                    strategy = std::make_unique<FullPriceStrategy>();
                }

                auto room = std::make_unique<Room>(id, price, std::move(strategy));
                hotel->addRoom(std::move(room));

                roomListBox->Items->Add("ID: " + id + ", Цена: " + price + ", Скидка: " + discount);
                this->Close();
            }
            catch (const std::exception& ex) {
                MessageBox::Show("Ошибка: " + gcnew String(ex.what()), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            catch (Exception^ ex) {
                MessageBox::Show("Ошибка: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void ClearButton_Click(Object^ sender, EventArgs^ e) {
            roomIdBox->Clear();
            roomPriceBox->Clear();
            discountBox->Clear();
        }
    };
}

