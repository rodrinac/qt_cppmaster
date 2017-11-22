import qbs
  
CppApplication {
    name : "17_intro_bd"
    files : "src/*"

    Depends { name: "Qt"; submodules: ["core", "sql"] }

    Group {
        name: "Script SQL"
        files: "sql/*"
    }
}

