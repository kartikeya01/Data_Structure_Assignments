#include <cassert>
#include <cstdio>
#include "barrel.h"

namespace data_structures_assignment_1
{

    barrel::barrel() {
        height = 1;
        water_liters = 0;
        olive_oil_liters = 0;
    }
    barrel::barrel(double init_height, double init_water_liters, double init_olive_oil_liters) {

        assert((init_height*100) >= (init_water_liters+init_olive_oil_liters));

        height = init_height;
        water_liters = init_water_liters;
        olive_oil_liters = init_olive_oil_liters;
    }

    void barrel::add_water(double liters) {

        assert(liters >= 0);

        if ((water_liters + liters + olive_oil_liters) <= get_total_capacity()) {
            water_liters = water_liters + liters;
            liters = 0;
        }

        if ((water_liters + liters + olive_oil_liters) > get_total_capacity()) {

            if (liters <= olive_oil_liters) {
                olive_oil_liters = olive_oil_liters - liters;
                water_liters = water_liters + liters;
                liters = 0;
            }

            if  (liters > olive_oil_liters) {
                if ((liters + water_liters) >= get_total_capacity()) {
                    olive_oil_liters = 0;
                    water_liters = get_total_capacity();
                }
                if ((liters + water_liters) < get_total_capacity()) {
                    water_liters = water_liters + liters;
                    olive_oil_liters = get_total_capacity() - water_liters;
                    liters = 0;
                }
            }
        }
    }

    void barrel::add_olive_oil(double liters) {

        assert(liters >= 0);

        if ((water_liters + liters + olive_oil_liters) <= get_total_capacity()) {
            olive_oil_liters = olive_oil_liters + liters;
            liters = 0;
        }

        if ((water_liters + liters + olive_oil_liters) > get_total_capacity()) {
            liters = get_total_capacity() - water_liters - olive_oil_liters;
            olive_oil_liters = olive_oil_liters + liters;
            liters = 0;
        }
    }


    void barrel::drain(double liters) {

        assert(liters >= 0);

        if (liters > (olive_oil_liters + water_liters)) {
            olive_oil_liters = 0;
            water_liters = 0;
            liters = 0;
        }

        if (water_liters >= liters) {
            water_liters = water_liters - liters;
            liters = 0;
        }

        if (liters > water_liters) {
            liters = liters - water_liters;
            water_liters = 0;
            olive_oil_liters = olive_oil_liters - liters;
            liters = 0;
        }

    }

    double barrel::get_water_liters() const {
        return water_liters;
    }
    double barrel::get_olive_oil_liters() const {
        return olive_oil_liters;
    }
    double barrel::get_height() const {
        return height;
    }
    double barrel::get_empty_space() const {
        return (get_total_capacity() - get_water_liters() - get_olive_oil_liters());
    }

    barrel operator+(const barrel &s1, const barrel &s2) {

        double x = (s1.get_height() + s2.get_height());
        double y = (s1.get_water_liters() + s2.get_water_liters());
        double z = (s1.get_olive_oil_liters() + s2.get_olive_oil_liters());
        barrel s3(x, y, z);
        return s3;
    }

    bool operator==(const barrel &s1, const barrel &s2) {

        return (s1.get_height() == s2.get_height()) &&
               (s1.get_water_liters() == s2.get_water_liters()) &&
               (s1.get_olive_oil_liters() == s2.get_olive_oil_liters());
    }
}
