Instructions
------------

    $ git clone https://github.com/jsmess/jsmess.git # or whichever fork you prefer
    $ cd jsmess
    $ git submodule update --init --recursive
    $ cd third-party/emscripten-fastcomp/tools
    $ ln -s ../../emscripten-fastcomp-clang clang
    $ cd ..
    $ mkdir build
    $ cd build
    $ ../configure --enable-optimized --disable-assertions --enable-targets=host,js
    $ make -j8
    $ ../../emscripten/emcc

Because you now made a very unusual LLVM setup doing this, you then
need to go into the ~/.emscripten file and edit the LLVM_ROOT variable
to wherever jsmess/third_party/emscripten-fastcomp/build/Release/bin/
is. Then, continue.

    $ cd ../../../helpers/
    $ ./genhelpers.sh

