import qbs

CppApplication {
    name : "qsqltablemodel_ex"
    files : ["src/*", "rc/img.qrc"]

    Depends { name: "Qt"; submodules: ["core", "sql", "gui", "widgets"] }

    Group {
        name: "Banco e Script SQLite"
        files: "sql/*"
    }
}

