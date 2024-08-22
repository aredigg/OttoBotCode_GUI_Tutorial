#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    wxArrayString choices;
    choices.Add("No");
    choices.Add("Yes");

    wxPanel *panel = new wxPanel(this);
    wxStaticText *staticText = new wxStaticText(panel, wxID_ANY, "Please rate this video (from 0-10)");
    wxSlider *slider = new wxSlider(panel, wxID_ANY, 5, 0, 10, wxDefaultPosition, wxSize(200, -1), wxSL_VALUE_LABEL);
    wxCheckBox *checkBox = new wxCheckBox(panel, wxID_ANY, "BoxSizers make sense now");
    wxRadioBox *radioBox = new wxRadioBox(panel, wxID_ANY, "Are you subscribed?", wxDefaultPosition, wxDefaultSize, choices);

    wxBoxSizer *boxSizer = new wxBoxSizer(wxVERTICAL);
    wxSizerFlags flags = wxSizerFlags().CenterHorizontal().Border(wxALL, 25);

    boxSizer->AddStretchSpacer();
    boxSizer->Add(staticText, flags);
    boxSizer->Add(slider, flags);
    boxSizer->Add(checkBox, flags);
    boxSizer->Add(radioBox, flags);
    boxSizer->AddStretchSpacer();

    panel->SetSizer(boxSizer);
    boxSizer->SetSizeHints(this);
    SetClientSize(800, 600);

};