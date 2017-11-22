import qbs
  
CppApplication {
    name : "qjsengine_ex"
    files : "src/*"

    Depends { name: "Qt"; submodules: ["core", "gui", "widgets", "qml"] }
}

