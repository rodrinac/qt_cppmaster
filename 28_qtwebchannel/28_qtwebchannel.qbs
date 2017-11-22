import qbs

CppApplication {
    name: "qtwebchannel_ex"
    files: "src/**"

    Depends { name: "Qt"; submodules: ["core", "websockets", "webchannel"] }

    Group { name: "Cliente HTML"; files: [ "client_html/**"] }
}
