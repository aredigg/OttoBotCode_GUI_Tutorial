#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString &title);
private:
    void OnAnyButtonClicked(wxCommandEvent &event);
    void OnButton1Clicked(wxCommandEvent &event);
    void OnButton2Clicked(wxCommandEvent &event);
    void OnClose(wxCloseEvent &event);
};