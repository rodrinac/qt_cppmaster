import qbs
  
CppApplication {
    name : "ponteiros_inteligentes_ex"
    files : "src/*"

    Depends { name: "Qt"; submodules: ["core"] }
}

