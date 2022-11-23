# copy template to new subdirectory
cp -r template/rnbo.example.ssp "modules/$1"

# update project name Make file
mv "modules/$1/CMakeLists.txt"  "modules/$1/CMakeLists.tmp"
sed "s/XXXX/$1/" "modules/$1/CMakeLists.tmp" > "modules/$1/CMakeLists.txt"

# add new module to build
echo "add_subdirectory($1)" >> modules/CMakeLists.txt
rm "modules/$1/CMakeLists.tmp"


# give users some instructions
echo EXPORT YOUR RNBO CODE TO:
echo modules/$1/rnbo_export
echo
echo
echo PREPARE BUILD :
echo mkdir build
echo cd build
echo cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=../xcSSP.cmake ..
echo
echo BUILD USING :
echo cmake --build .

echo
echo
echo for more detailed instructions read:
echo docs/BUILDING.md
