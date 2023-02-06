rm -r *.cmake
rm -r Makefile
rm -r CMakeFiles
rm CMakeCache.txt

cd ./Global
rm -r *.cmake
rm -r Makefile
rm -r CMakeFiles

cd ..
cd ./Server
rm -r *.cmake
rm -r Makefile
rm -r CMakeFiles

cd ..
cd ./Client
rm -r *.cmake
rm -r Makefile
rm -r CMakeFiles

cd ..
cd ./bin
rm Client
rm Server
rm *.a
rm *.log