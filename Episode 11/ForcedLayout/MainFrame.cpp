#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {
    wxPanel *panel = new wxPanel(this);
    wxButton *button = new wxButton(panel, wxID_ANY, "Centered Button", wxPoint(375, 250), wxSize(250, -1));
};