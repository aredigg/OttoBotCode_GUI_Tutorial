#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    wxPanel *panel = new wxPanel(this);
    button = new wxButton(panel, wxID_ANY, "Centered Button", wxPoint(375, 250), wxSize(250, 100));
    Bind(wxEVT_SIZE, &MainFrame::OnResize, this);
};

void MainFrame::OnResize(wxSizeEvent &event) {
    wxSize clientSize = GetClientSize();
    wxSize buttonSize(clientSize.GetWidth()>>2, 100);
    int buttonX = (clientSize.GetWidth() - buttonSize.GetWidth())>>1;
    int buttonY = (clientSize.GetHeight() - buttonSize.GetHeight())>>1;
    button->SetSize(buttonSize);
    button->SetPosition(wxPoint(buttonX, buttonY));
    event.Skip();
}