#include "Callbacks.h"
#include <string>

#include "EditorWindow.h"
#include "Variables.h"

#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Text_Editor.H>

void set_title(Fl_Window *widget) {
  if (filename[0] == '\0') {
    title.assign("Untitled");
  } else {
    char *slash;
    slash = strchr(filename, '/');
#ifdef WIN32
    if (slash == NULL) {
      slash = strchr(filename, '\\');
    }
#endif
    if (slash != NULL) {
      title.assign(slash + 1);
    } else {
      title.assign(filename);
    }
  }
  if (changed) {
    title.append(" (modified)");
  }
  widget->label(title.c_str());
}

void save_file(char *newfile) {}
