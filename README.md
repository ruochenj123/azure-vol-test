1. Install azure-storage-cpp via vcpkg
2. Download and compile HDF5 1.13 (https://portal.hdfgroup.org/display/support/HDF5%201.13.3)
3. Download and compile the tes code
```
git clone https://github.com/ruochenj123/azure-vol-test.git
cd $HOME/azure-vol-test
cmake -B ./build -S . -DCMAKE_TOOLCHAIN_FILE=PATH_TO_VCPKG/vcpkg/scripts/buildsystems/vcpkg.cmake
cd build
make
```
4. Add environment variable
```
export AZURE_STORAGE_CONNECTION_STRING=XXXX
export BUCKET_NAME=XXXX
export HDF5_PLUGIN_PATH=$HOME/azure-vol-test/build/src
````
5. Run the test
```
./build/test/write
```