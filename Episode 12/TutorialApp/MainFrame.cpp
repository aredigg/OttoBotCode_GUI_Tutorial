#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    wxButton *button1 = new wxButton(this, wxID_ANY, "Button 1", wxDefaultPosition, wxSize(300, 100));
    wxButton *button2 = new wxButton(this, wxID_ANY, "Button 2", wxDefaultPosition, wxSize(300, 100));

    wxBoxSizer *boxSizer = new wxBoxSizer(wxHORIZONTAL);

    boxSizer->AddStretchSpacer();
    boxSizer->Add(button1);
    boxSizer->Add(button2);
    boxSizer->AddStretchSpacer();

    SetSizerAndFit(boxSizer);
};