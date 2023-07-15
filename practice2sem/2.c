#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double G = 9.81;

struct coordinates {
    double x, y, z;
};

struct coordinates get_a(double S, double t) {
    struct coordinates coordinates = {0, 0, -G};
    return coordinates;

}

double get_s(double s0, double v, double dt, double a) {
    return (s0 + v * dt + ((a * pow(dt, 2)) / 2));
}

double get_v(double v0, double a, double t) {
    return v0 + a * t;
}

void appendCoordinates(struct coordinates **arr, int *size, struct coordinates newCoord) {
    *size += 1;

    struct coordinates *newArr = (struct coordinates *) realloc(*arr, (*size) * sizeof(struct coordinates));

    if (newArr == NULL) {
        exit(1);
    }

    *arr = newArr;
    (*arr)[*size - 1] = newCoord;
}

void fill_array(struct coordinates **array, int *size, struct coordinates initial_coordinates,
                struct coordinates initial_speed, double dt) {
    appendCoordinates(array, size, initial_coordinates);

    int i = 0;
    while ((*array)[i].z >= 0) {
        double t = dt * i;
        struct coordinates a = get_a(0, t);
        struct coordinates s;
        s.x = get_s((*array)[i].x, initial_speed.x, dt, get_v(initial_speed.x, a.x, t));
        s.y = get_s((*array)[i].y, initial_speed.y, dt, get_v(initial_speed.y, a.y, t));
        s.z = get_s((*array)[i].z, initial_speed.z, dt, get_v(initial_speed.z, a.z, t));
        appendCoordinates(array, size, s);
        i++;
    }
}

int main() {

    printf("2. Calculate equations.\n\n");

    struct coordinates *array = NULL;
    int size = 0;

    struct coordinates initial_coordinates = {0, 0, 100};
    struct coordinates initial_speed = {3, 4, 5};

    fill_array(&array, &size, initial_coordinates, initial_speed, 0.1);

    printf("X Y Z\n");
    for (int i = 0; i < size - 1; ++i) {
        printf("%lf %lf %lf\n", array[i].x, array[i].y, array[i].z);
    }

    free(array);

    return 0;
}
