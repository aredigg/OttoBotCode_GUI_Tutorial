#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString &title);
private:
    void OnResize(wxSizeEvent &event);
    wxButton *button;
};