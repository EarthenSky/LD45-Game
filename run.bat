mingw32-make PLATFORM=PLATFORM_WEB -B

move arena.html out/arena.html
move arena.js out/arena.js
move arena.js.orig.js out/arena.js.orig.js
move arena.wasm out/arena.wasm
move arena.data out/arena.data

cd out
C:\python27\python.exe -m SimpleHTTPServer 8080

mingw32-make clean