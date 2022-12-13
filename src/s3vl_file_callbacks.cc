#include "s3vl_file_callbacks.h"
#include <stdlib.h>

void* S3VLFileCallbacks::S3VL_file_create(const char *name, unsigned flags, hid_t fcpl_id, hid_t fapl_id, hid_t dxpl_id, void **req) {
	string azure_connection_string = std::getenv("AZURE_STORAGE_CONNECTION_STRING");
    auto containerClient
      = BlobContainerClient::CreateFromConnectionString(azure_connection_string, "hyperslab-test");

    containerClient.CreateIfNotExists();
    BlockBlobClient blclient = containerClient.GetBlockBlobClient("test");
    uint8_t buffer[5] = {1, 2, 3, 4, 5};
    blclient.UploadFrom(buffer, 5);
	return NULL;
}