time g++ -std=c++17 *.cpp -o RoboSim  -g -pthread -fpermissive -Iexternal -lraylib   # compile
#x86_64-w64-mingw32-gcc *.cpp -o RoboSim.exe -Iexternal -lraylib

./RoboSim # --DEBUG_INFO # run