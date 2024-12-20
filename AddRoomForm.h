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
//	/// ������ ��� AddRoomForm
//	/// </summary>
//	public ref class AddRoomForm : public System::Windows::Forms::Form
//	{
//	public:
//		AddRoomForm(void)
//		{
//			InitializeComponent();
//			//
//			//TODO: �������� ��� ������������
//			//
//		}
//
//	protected:
//		/// <summary>
//		/// ���������� ��� ������������ �������.
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
//		/// ������������ ���������� ������������.
//		/// </summary>
//		System::ComponentModel::Container ^components;
//
//#pragma region Windows Form Designer generated code
//		/// <summary>
//		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
//		/// ���������� ����� ������ � ������� ��������� ����.
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

            this->Text = "�������� �������";
            this->Size = System::Drawing::Size(400, 300);

            Label^ label1 = gcnew Label();
            label1->Text = "ID �������:";
            label1->Location = Point(10, 10);
            this->Controls->Add(label1);

            roomIdBox = gcnew TextBox();
            roomIdBox->Location = Point(150, 10);
            this->Controls->Add(roomIdBox);

            Label^ label2 = gcnew Label();
            label2->Text = "���� �������:";
            label2->Location = Point(10, 50);
            this->Controls->Add(label2);

            roomPriceBox = gcnew TextBox();
            roomPriceBox->Location = Point(150, 50);
            this->Controls->Add(roomPriceBox);

            Label^ label3 = gcnew Label();
            label3->Text = "������ (%):";
            label3->Location = Point(10, 90);
            this->Controls->Add(label3);

            discountBox = gcnew TextBox();
            discountBox->Location = Point(150, 90);
            this->Controls->Add(discountBox);

            Button^ saveButton = gcnew Button();
            saveButton->Text = "���������";
            saveButton->Location = Point(10, 130);
            saveButton->Click += gcnew EventHandler(this, &AddRoomForm::SaveButton_Click);
            this->Controls->Add(saveButton);

            Button^ clearButton = gcnew Button();
            clearButton->Text = "��������";
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

                roomListBox->Items->Add("ID: " + id + ", ����: " + price + ", ������: " + discount);
                this->Close();
            }
            catch (const std::exception& ex) {
                MessageBox::Show("������: " + gcnew String(ex.what()), "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            catch (Exception^ ex) {
                MessageBox::Show("������: " + ex->Message, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void ClearButton_Click(Object^ sender, EventArgs^ e) {
            roomIdBox->Clear();
            roomPriceBox->Clear();
            discountBox->Clear();
        }
    };
}

