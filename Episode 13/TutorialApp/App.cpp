#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    MainFrame *mainFrame = new MainFrame("Tutorial App");
    mainFrame->Show();
    return true;
}