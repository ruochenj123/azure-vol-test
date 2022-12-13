#ifndef S3VL_FILE_CALLBACKS
#include <string>
#include <hdf5.h>
#include <azure/storage/blobs.hpp>
using namespace std;
using namespace Azure::Storage::Blobs;


typedef struct S3VLFileObj {
	string name;
} S3VLFileObj;

class S3VLFileCallbacks{
public:
	static void *S3VL_file_create(const char *name, unsigned flags, hid_t fcpl_id, hid_t fapl_id, hid_t dxpl_id, void **req);
};
#define S3VL_FILE_CALLBACKS
#endif