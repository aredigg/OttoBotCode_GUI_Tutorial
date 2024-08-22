#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    wxPanel *panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS);
    wxButton *button1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 150), wxSize(200, 100));
    wxButton *button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 100));

    panel->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnKeyEvent, this);
    CreateStatusBar();
}

void MainFrame::OnKeyEvent(wxKeyEvent &event) {
    if (event.GetKeyCode() == WXK_TAB) {
        wxWindow  *window = (wxWindow *) event.GetEventObject();
        window->Navigate();
    }
    wxChar keyChar = event.GetUnicodeKey();

    if (keyChar == WXK_NONE) {
        int keyCode = event.GetKeyCode();
        wxLogStatus("Key event %d", keyCode);
    } else {
        wxLogStatus("Key event %c", keyChar);
    }
}