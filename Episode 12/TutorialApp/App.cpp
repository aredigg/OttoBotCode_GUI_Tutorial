#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    MainFrame *mainFrame = new MainFrame("Tutorial App");
    mainFrame->SetClientSize(1000,600);
    mainFrame->Center();
    mainFrame->Show();
    return true;
}