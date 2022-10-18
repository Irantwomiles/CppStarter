//
// Created by Shayan on 10/18/2022.
//

#include <iostream>
#include <proj.h>

void Test_Proj();

int main() {

    std::cout << "File built using vcpkg" << std::endl;

    Test_Proj();

    return 0;
}

void Test_Proj() {

    PJ_CONTEXT *C;
    PJ *P;
    PJ *norm;
    PJ_COORD a, b;

    C = proj_context_create();

    P = proj_create_crs_to_crs (C,
                                "EPSG:4326",
                                "+proj=utm +zone=32 +datum=WGS84", /* or EPSG:32632 */
                                NULL);

    if (0 == P) {
        fprintf(stderr, "Failed to create transformation object.\n");
        std::cout << "Failed to create transformation object" << std::endl;
        return;
    }

    std::cout << P << std::endl;

}