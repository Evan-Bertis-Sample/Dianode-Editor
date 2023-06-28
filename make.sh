cmake -Wno-dev -GNinja -DCMAKE_BUILD_TYPE=Debug -DWARNINGS_AS_ERRORS=FALSE -B build/debug
ninja -C build/debug
cd ./build/debug/src/app && ./App
cd ../../../..