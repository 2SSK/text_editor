#include "EditorWindow.h"

// Global variables
int changed{};
char filename[256] = "";
Fl_Text_Buffer *textbuf = new Fl_Text_Buffer();

EditorWindow::EditorWindow(int w, int h, const char *t)
    : Fl_Double_Window(w, h, t) {

  // Create and configure the main text editor.
  editor = new Fl_Text_Editor(10, 10, w - 20, h - 50);
  editor->buffer(textbuf); // Link the text editor to the text buffer.

  // Initialize the replace dialog components (initially hidden)
  replace_dlg = new Fl_Window(300, 150, "Replace");
  replace_find = new Fl_Input(120, 10, 170, 25, "Find:");
  replace_with = new Fl_Input(120, 40, 170, 25, "Replace:");
  replace_all = new Fl_Button(10, 100, 90, 30, "Replace All");
  replace_next = new Fl_Return_Button(110, 100, 90, 30, "Replace Next");
  replace_cancel = new Fl_Button(210, 100, 90, 30, "Cancel");
  replace_dlg->end();
  replace_dlg->hide(); // Hide the dialog initially.

  end();  
}

EditorWindow::~EditorWindow() {
  delete replace_dlg;
  delete editor;
}
