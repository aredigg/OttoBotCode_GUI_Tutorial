#include "MainFrame.h"
#include <wx/wx.h>
#include <vector>
#include <string>
#include "Task.h"

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    CreateControls();
    SetupSizers();
    BindEventHandlers();
    AddSavedTasks();
}

void MainFrame::CreateControls() {
    wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0, 15)));

    panel = new wxPanel(this);
    panel->SetFont(mainFont);

    headlineText = new wxStaticText(panel, wxID_ANY, "To-Do List");
    headlineText->SetFont(headlineFont);

    inputField = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
    addButton = new wxButton(panel, wxID_ANY, "Add");
    checkListBox = new wxCheckListBox(panel, wxID_ANY);
    clearButton = new wxButton(panel, wxID_ANY, "Clear");
}

void MainFrame::SetupSizers() {
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(headlineText, wxSizerFlags().CenterHorizontal());
    mainSizer->AddSpacer(25);

    wxBoxSizer *inputSizer = new wxBoxSizer(wxHORIZONTAL);
    inputSizer->Add(inputField, wxSizerFlags().Proportion(1));
    inputSizer->AddSpacer(5);
    inputSizer->Add(addButton);

    mainSizer->Add(inputSizer, wxSizerFlags().Expand());
    mainSizer->AddSpacer(5);
    mainSizer->Add(checkListBox, wxSizerFlags().Expand().Proportion(1));
    mainSizer->AddSpacer(5);
    mainSizer->Add(clearButton);

    wxGridSizer *outerSizer = new wxGridSizer(1);
    outerSizer->Add(mainSizer, wxSizerFlags().Border(wxALL, 25).Expand());

    panel->SetSizer(outerSizer);
    outerSizer->SetSizeHints(this);
}

void MainFrame::BindEventHandlers() {
    addButton->Bind(wxEVT_BUTTON, &MainFrame::OnAddButtonClicked, this);
    inputField->Bind(wxEVT_TEXT_ENTER, &MainFrame::OnInputEnter, this);
    checkListBox->Bind(wxEVT_KEY_DOWN, &MainFrame::OnListKeyDown, this);
    clearButton->Bind(wxEVT_BUTTON, &MainFrame::OnClearButtonClicked, this);
    this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnWindowClosed, this);
}

void MainFrame::AddSavedTasks() {
    std::vector<Task> tasks = LoadTasksFromFile("tasks.txt");
    for (const Task &task : tasks) {
        int index = checkListBox->GetCount();
        checkListBox->Insert(task.description, index);
        checkListBox->Check(index, task.done);
    }
}

void MainFrame::OnAddButtonClicked(wxCommandEvent &event) {
    AddTaskFromInput();
}

void MainFrame::OnInputEnter(wxCommandEvent &event) {
    AddTaskFromInput();
}

void MainFrame::OnListKeyDown(wxKeyEvent &event) {
    switch (event.GetKeyCode()) {
    case WXK_DELETE:
        DeleteSelectedTask();
        break;
    case WXK_UP:
        MoveSelectedTask(-1);
        break;
    case WXK_DOWN:
        MoveSelectedTask(+1);
        break;
    }
}

void MainFrame::OnClearButtonClicked(wxCommandEvent &event) {
    if (checkListBox->IsEmpty()) {
        return;
    }
    wxMessageDialog dialog(this, "Are you sure you want to clear all tasks?", "Clear", wxYES_NO | wxCANCEL);
    int result = dialog.ShowModal();

    if (result == wxID_YES) {
        checkListBox->Clear();
    }
}

void MainFrame::OnWindowClosed(wxCloseEvent &event) {
    std::vector<Task> tasks;
    for (int i = 0; i < checkListBox->GetCount(); i++) {
        Task task;
        task.description = checkListBox->GetString(i);
        task.done = checkListBox->IsChecked(i);
        tasks.push_back(task);
    }
    SaveTasksToFile(tasks, "tasks.txt");
    event.Skip();
}

void MainFrame::AddTaskFromInput() {
    wxString description = inputField->GetValue();

    if (!description.IsEmpty()) {
        checkListBox->Insert(description, checkListBox->GetCount());
        inputField->Clear();
    }

    inputField->SetFocus();
}

void MainFrame::DeleteSelectedTask() {
    int selectedIndex = checkListBox->GetSelection();
    if (selectedIndex == wxNOT_FOUND) {
        return;
    }
    checkListBox->Delete(selectedIndex);
}

void MainFrame::MoveSelectedTask(int offset) {
    int selectedIndex = checkListBox->GetSelection();
    if (selectedIndex == wxNOT_FOUND) {
        return;
    }
    int newIndex = selectedIndex + offset;
    if (newIndex >= 0 && newIndex < checkListBox->GetCount()) {
        SwapTasks(selectedIndex, newIndex);
        checkListBox->SetSelection(newIndex, true);
    }
}

void MainFrame::SwapTasks(int i, int j) {
    Task taskI{checkListBox->GetString(i).ToStdString(), checkListBox->IsChecked(i)};
    Task taskJ{checkListBox->GetString(j).ToStdString(), checkListBox->IsChecked(j)};
    checkListBox->SetString(i, taskJ.description);
    checkListBox->Check(i, taskJ.done);
    checkListBox->SetString(j, taskI.description);
    checkListBox->Check(j, taskI.done);
}