#include "s3vl_vol_connector.h"
#include <hdf5.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(void)
{

    hid_t fapl = H5Pcreate(H5P_FILE_ACCESS);

    hid_t vol_id = H5VLregister_connector_by_name(S3_VOL_CONNECTOR_NAME, H5P_DEFAULT);
    if (H5Pset_vol(fapl, vol_id, NULL) < 0)
        printf("vol failed\n");
    
    H5Fcreate("test.h5", H5F_ACC_TRUNC, H5P_DEFAULT, fapl);
    H5VLunregister_connector(vol_id);
    return 0;

} /* end main() */

