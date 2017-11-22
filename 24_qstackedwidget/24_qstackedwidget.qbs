import qbs

CppApplication {
    name: "qstackedwidget_ex"
    files: "src/**"

    Depends { name: "Qt"; submodules: ["core", "gui", "widgets", "sql"] }

    Group { name: "Script SQL"; files: [ "sql/*"] }
}
