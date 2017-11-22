import qbs
  
CppApplication {
    name : "qinputdialog_ex"
    files : "src/*"

    Depends { name: "Qt"; submodules: ["core", "gui", "widgets"] }
}

