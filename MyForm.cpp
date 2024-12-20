//#include "MyForm.h"
//
//
//
//using namespace System;
//using namespace System::Windows::Forms;
//
//[STAThread]
//void Main() {
//    Application::EnableVisualStyles();
//    Application::SetCompatibleTextRenderingDefault(false);
//    Application::Run(gcnew HotelManager::MainForm());
//}
//

//2 вариант
//#include "MyForm.h"
//
//using namespace System;
//using namespace System::Windows::Forms;
//
//[STAThread]
//void Main() {
//    Application::EnableVisualStyles();
//    Application::SetCompatibleTextRenderingDefault(false);
//    Application::Run(gcnew HotelManager::MyForm());
//}
//конец 2 варианта


#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew HotelManager::MainForm());

}























//using namespace System;
//using namespace System::Windows::Forms;
//
//[STAThread]
//void Main() {
//    Application::EnableVisualStyles();
//    Application::SetCompatibleTextRenderingDefault(false);
//
//    TabControl^ tabControl = gcnew TabControl();
//    tabControl->Dock = DockStyle::Fill;
//
//    Form^ tabbedForm = gcnew Form();
//    tabbedForm->Text = "Управление отелем";
//    tabbedForm->Size = System::Drawing::Size(400, 400);
//
//    TabPage^ mainTab = gcnew TabPage("Главное меню");
//    mainTab->Controls->Add(gcnew HotelManager::MainForm());
//    mainTab->Dock = DockStyle::Fill;
//
//    TabPage^ addRoomTab = gcnew TabPage("Добавить комнату");
//    addRoomTab->Controls->Add(gcnew HotelManager::AddRoomForm());
//    addRoomTab->Dock = DockStyle::Fill;
//
//    tabControl->Controls->Add(mainTab);
//    tabControl->Controls->Add(addRoomTab);
//
//    tabbedForm->Controls->Add(tabControl);
//
//    Application::Run(tabbedForm);
//}
