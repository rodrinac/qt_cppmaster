import qbs
  
CppApplication {
    name: "qtwebapp_ex"
    files: "src/*"
    cpp.includePaths: "../QtWebApp/QtWebApp"
    cpp.libraryPaths: "../QtWebApp/build"
    cpp.dynamicLibraries: "QtWebAppd1"

    Depends { name: "Qt"; submodules: ["core", "network"] }
}

