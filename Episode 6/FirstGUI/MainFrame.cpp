#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    wxPanel *panel = new wxPanel(this);
    wxButton *button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 275), wxSize(200, 50));
    wxSlider *slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
    wxTextCtrl *text = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 375), wxSize(200, -1));

    button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
    text->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);

    button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

    CreateStatusBar();
}

void MainFrame::OnButtonClicked(wxCommandEvent &event) {
    wxLogStatus("Button Clicked");
}

void MainFrame::OnSliderChanged(wxCommandEvent &event) {
    wxString str = wxString::Format("Slider value: %d", event.GetInt());
    wxLogStatus(str);
}

void MainFrame::OnTextChanged(wxCommandEvent &event) {
    wxString str = wxString::Format("Text: %s", event.GetString());
    wxLogStatus(str);
}