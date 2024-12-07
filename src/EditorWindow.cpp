#include "EditorWindow.h"
#include <FL/fl_ask.H>

// Global variables
int changed{}; // Indicates if the file has unsaved changes
char filename[256] = "";
Fl_Text_Buffer *textbuf = new Fl_Text_Buffer();

// Callback to track changes in the text buffer
void changed_cb(int, int, int, int, const char *, void *userdata) {
  auto *window = static_cast<EditorWindow *>(userdata);
  if (!changed) {
    window->label("FLTK Text Editor*");
    changed = 1;
  }
}

// Dummy callbacks for menu items
void open_ch(Fl_Widget *, void *) { fl_message("Open File selected"); }

void save_ch(Fl_Widget *, void *) { fl_message("Open File Clicked"); }

void exit_ch(Fl_Widget *, void *) {
  int choice =
      fl_choice("Are you sure you want to exit?", "No", "Yes", nullptr);

  if (choice == 1) { // "Yes" is the second option, index 1
    exit(0);
  } else {
    exit(0);
  }
}

// Menu items array
Fl_Menu_Item menuitems[] = {
    {"&File", 0, 0, 0, FL_SUBMENU},
    {"&Open File...", FL_CTRL + 'o', nullptr},
    {"&Insert File...", FL_CTRL + 'i', nullptr, 0, FL_MENU_DIVIDER},
    {"&Save File...", FL_CTRL + 's', nullptr},
    {"&Save File &As...", FL_CTRL + FL_SHIFT + 'o', nullptr, 0,
     FL_MENU_DIVIDER},
    {"&Exit", FL_CTRL + 'q', nullptr},
    {0},

    {"&Edit", 0, 0, 0, FL_SUBMENU},
    {"&Undo", FL_CTRL + 'z', nullptr},
    {"Cu&t", FL_CTRL + 'x', nullptr},
    {"&Copy", FL_CTRL + 'c', nullptr},
    {"&Paste", FL_CTRL + 'v', nullptr},
    {"&Delete", 0, nullptr},
    {0},

    {"&Search", 0, 0, 0, FL_SUBMENU},
    {"&Find...", FL_CTRL + 'f', nullptr},
    {"&Replace...", FL_CTRL + 'r', nullptr},
    {0},

    {0}};

EditorWindow::EditorWindow(int w, int h, const char *t)
    : Fl_Double_Window(w, h, t) {

  // Create a menu bar
  menu = new Fl_Menu_Bar(0, 0, w, 30);
  menu->copy(menuitems);

  // Create and configure the main text editor.
  editor = new Fl_Text_Editor(0, 30, w, h - 60);
  editor->buffer(textbuf);      // Link the text editor to the text buffer.
  editor->textfont(FL_COURIER); // Set the editor font to Courier.

  // Add Modify callback to track changes
  textbuf->add_modify_callback(changed_cb, this);

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
  delete menu;
  delete editor;
  delete textbuf;
}
