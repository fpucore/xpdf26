//========================================================================
//
// xpdf.cc
//
// Copyright 2026 Chris McGimpsey-Jones <chrisjones.unixmen@gmail.com>
// Copyright 1996-2025 Glyph & Cog, LLC
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
//========================================================================

#include <aconf.h>

#include "gmem.h"
#include "Object.h"
#include "XpdfApp.h"
#include "gmempp.h"

int main(int argc, char *argv[]) {
  int exitCode;

  {
    // this is inside a block so that the XpdfApp object gets freed
    XpdfApp app(argc, argv);

    app.setStyleSheet(
        "QWidget { background-color: #000000; color: #ffffff; "
        "selection-background-color: #ff0000; selection-color: #ffffff; }"
        "QToolBar { background-color: #111111; border-bottom: 1px solid #ff0000; }"
        "QMenu { background-color: #111111; color: #ffffff; border: 1px solid #ff0000; }"
        "QMenu::item:selected { background-color: #ff0000; color: #ffffff; }"
        "QLineEdit { background-color: #222222; color: #ffffff; border: 1px solid #ff0000; }"
        "QListWidget, QTreeView, QTableWidget { background-color: #000000; color: #ffffff; }"
        "QScrollBar:vertical { background-color: #111111; width: 14px; }"
        "QScrollBar:horizontal { background-color: #111111; height: 14px; }"
        "QScrollBar::handle { background-color: #ff0000; border-radius: 2px; }"
        "QScrollBar::add-line, QScrollBar::sub-line { width: 0px; height: 0px; border: none; }"
        "QSplitter::handle { background-color: #ff0000; }"
    );

    if (app.getNumViewers() > 0) {
      exitCode = app.exec();
    } else {
      exitCode = 1;
    }
  }

  Object::memCheck(stderr);
  gMemReport(stderr);

  return exitCode;
}

#ifdef _WIN32
int CALLBACK WinMain(HINSTANCE hIstance, HINSTANCE hPrevInstance,
		     LPSTR lpCmdLine, int nCmdShow) {
  wchar_t **args;
  int argc, i, n, ret;

  if (!(args = CommandLineToArgvW(GetCommandLineW(), &argc)) ||
      argc < 0) {
    return -1;
  }
  char **argv = (char  **)gmallocn(argc + 1, sizeof(char *));
  for (i = 0; i < argc; ++i) {
    n = WideCharToMultiByte(CP_UTF8, 0, args[i], -1, NULL, 0, NULL, NULL);
    argv[i] = (char *)gmalloc(n);
    WideCharToMultiByte(CP_UTF8, 0, args[i], -1, argv[i], n, NULL, NULL);
  }
  argv[argc] = NULL;
  LocalFree(args);
  ret = main(argc, argv);
  for (i = 0; i < argc; ++i) {
    gfree(argv[i]);
  }
  gfree(argv);
  return ret;
}
#endif
