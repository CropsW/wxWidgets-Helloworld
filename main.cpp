// wxWidgets "Hello World" Program



#include <wx/wx.h>


class MyApp : public wxApp {
public:
    virtual bool OnInit ();
};

class MyFrame : public wxFrame {
public:
    MyFrame ();

private:
    void OnHello (wxCommandEvent &event);

    void OnExit (wxCommandEvent &event);

    void OnAbout (wxCommandEvent &event);
};


IMPLEMENT_APP(MyApp);

bool MyApp::OnInit () {
  auto *frame = new MyFrame ();
  frame->Show (true);
  return true;
}

MyFrame::MyFrame ()
        : wxFrame (nullptr, wxID_ANY, "Hello World") {
  auto *menuFile = new wxMenu;
  menuFile->Append (1, "&Hello...\tCtrl-H",
                    "Help string shown in status bar for this menu item");
  menuFile->AppendSeparator ();
  menuFile->Append (wxID_EXIT);

  auto *menuHelp = new wxMenu;
  menuHelp->Append (wxID_ABOUT);

  auto *menuBar = new wxMenuBar;
  menuBar->Append (menuFile, "&File");
  menuBar->Append (menuHelp, "&Help");

  SetMenuBar (menuBar);


  Bind (wxEVT_MENU, &MyFrame::OnHello, this, 1);
  Bind (wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
  Bind (wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnExit (wxCommandEvent &event) {
  Close (true);
}

void MyFrame::OnAbout (wxCommandEvent &event) {
  wxMessageBox ("This is a wxWidgets Hello World example",
                "Abouzt Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello (wxCommandEvent &event) {
  wxLogMessage ("Hello world from wxWidgets!");
}

