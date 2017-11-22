import qbs
  
CppApplication {
    name: "qsystemtryicon_ex"
    files: ["src/*", "rc/imagens.qrc"]

    Depends { name: "Qt"; submodules: ["core", "gui", "widgets"] }
}

