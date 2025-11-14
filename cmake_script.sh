#rm Makefile
#rm CMakeCache.txt
#rm -r CMakeFiles
#rm cmake_install.cmake
#cmake -DGeant4_DIR=/data1/cangus/Geant4/geant4-v11.3.2 /data1/cangus/Geant4/G4EMMA

rm Makefile
rm CMakeCache.txt
rm -r CMakeFiles
rm cmake_install.cmake
cmake \
  -DGeant4_DIR=/data1/cangus/Geant4/geant4-v11.3.2 \
  -DCMAKE_POSITION_INDEPENDENT_CODE=OFF \
  -DCMAKE_EXE_LINKER_FLAGS="-no-pie" \
  /data1/cangus/Geant4/G4EMMA
