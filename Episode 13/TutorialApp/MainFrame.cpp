#include "MainFrame.h"
#include <wx/wx.h>
#include <vector>

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    wxPanel *panel = new wxPanel(this);
    std::vector<wxButton *> buttons;

    for (int i = 0; i < 7; i++) {
        wxString label = wxString::Format("Button %d", i+1);
        wxButton *button = new wxButton(panel, wxID_ANY, label, wxDefaultPosition, wxSize(300, -1));
        buttons.push_back(button);
    }

    wxGridSizer *gridSizer = new wxGridSizer(0, 2, wxSize(0, 0));
    wxSizerFlags flags = wxSizerFlags().Border(wxALL, 5);

    for (wxButton *button : buttons) {
        gridSizer->Add(button, flags);
    }

    panel->SetSizer(gridSizer);
    gridSizer->SetSizeHints(this);
};