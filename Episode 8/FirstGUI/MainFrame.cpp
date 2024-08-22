#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    wxPanel *panel = new wxPanel(this);

    wxButton *button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 250), wxSize(200,100));

    wxStatusBar *statusBar = CreateStatusBar();
    statusBar->SetDoubleBuffered(true);

    panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
    button->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
}

void MainFrame::OnMouseEvent(wxMouseEvent &event) {
    wxPoint mousePos = wxGetMousePosition();
    mousePos = this->ScreenToClient(mousePos);
    wxString message = wxString::Format("Mouse Event Detected! (x=%d y=%d)", mousePos.x, mousePos.y);
    wxLogStatus(message);
}

