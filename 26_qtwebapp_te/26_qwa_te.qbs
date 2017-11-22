import qbs
  
CppApplication {
    name: "qtwebapp_ex"
    files: "src/*"
    cpp.includePaths: "../QtWebApp/QtWebApp"
    cpp.libraryPaths: "../QtWebApp/build"
    cpp.dynamicLibraries: "QtWebAppd1"

    Depends { name: "Qt"; submodules: ["core", "network"] }
    
    Group { name: "Cliente HTML"; files: "form/*"}
    Group { name: "Templ. Engine"; files: "templates/*"}
}

