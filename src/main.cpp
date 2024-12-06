#include "EditorWindow.h"
#include <FL/Fl.H>

int main(int argc, char **argv) {
  /*
   * Create the main editor window with
   * size : 800 x 600
   * title : "FLTK Text Editor"
   */
  EditorWindow *window = new EditorWindow(800, 600, "FLTK Text Editor");

  // Display the window and start the FLTK event loop.
  window->show(argc, argv);

  // Start the FLTK event loop, keeping the application running.
  return Fl::run();
}
