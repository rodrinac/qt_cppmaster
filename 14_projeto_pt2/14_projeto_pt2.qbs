import qbs
  
CppApplication {
    name : "html_editor"
    files : ["src/*", "rc/image.qrc"]

    Depends { name: "Qt"; submodules: ["core", "gui", "widgets"] }
}

