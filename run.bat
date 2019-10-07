mingw32-make PLATFORM=PLATFORM_WEB -B

move main.html out/main.html
move main.js out/main.js
move main.js.orig.js out/main.js.orig.js
move main.wasm out/main.wasm
move main.data out/main.data

cd out
C:\python27\python.exe -m SimpleHTTPServer 8080