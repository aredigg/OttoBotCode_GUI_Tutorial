#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString &title);
private:
    void OnKeyEvent(wxKeyEvent &event);
};