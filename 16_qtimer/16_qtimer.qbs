import qbs
  
CppApplication {
    name : "qtimer_ex"
    files : "src/*"

    Depends { name: "Qt"; submodules: ["core"] }
}

