import qbs
  
CppApplication {
    name : "qsqlquerymodel_ex"
    files : "src/*"

    Depends { name: "Qt"; submodules: ["core", "sql", "gui", "widgets"] }

    Group {
        name: "Script SQL"
        files: "sql/*"
    }
}

