#ifndef EDITOR_WINDOW_H
#define EDITOR_WINDOW_H

#include <string>

#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Window.H>

class EditorWindow : public Fl_Window {
public:
  EditorWindow(int wdith, int height, std::string *title);
  ~EditorWindow();

  // UI components for the search and replace dialog
  Fl_Window *replace_dlg;
  Fl_Input *replace_find;
  Fl_Input *replace_with;
  Fl_Button *replace_all;
  Fl_Return_Button *replace_next;
  Fl_Button *replace_cancel;

  // Main text editor component
  Fl_Text_Editor *editor;
  char search[256];
};

#endif
