import qbs
  
CppApplication {
    consoleApplication: true
    name : "json_ex"
    files : "src/*"    

    Depends { name: "Qt.core" }
}

