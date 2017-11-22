import qbs
  
CppApplication {
    name : "query_list_table"
    files : ["src/*", "rc/images.qrc"]

    Depends { name: "Qt"; submodules: ["core", "sql", "gui", "widgets"] }

    Group {
        name: "Script SQL"
        files: "sql/*"
    }
}

