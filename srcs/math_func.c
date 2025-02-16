
#include "../includes/fdf.h"

#include <math.h>  // For cos() and sin()

void rotate_all(t_vector *v, int angle_x, int angle_y, int angle_z)
{
    // Convert angles to radians
    double angle_x_rad = angle_x * (M_PI / 180.0);
    double angle_y_rad = angle_y * (M_PI / 180.0);
    double angle_z_rad = angle_z * (M_PI / 180.0);

    // Precompute sine and cosine values
    double cos_x = cos(angle_x_rad), sin_x = sin(angle_x_rad);
    double cos_y = cos(angle_y_rad), sin_y = sin(angle_y_rad);
    double cos_z = cos(angle_z_rad), sin_z = sin(angle_z_rad);

    // Rotate around the X-axis
    double new_y = cos_x * v->y - sin_x * v->z;
    double new_z = sin_x * v->y + cos_x * v->z;

    v->y = new_y;
    v->z = new_z;

    // Rotate around the Y-axis
    double new_x = cos_y * v->x + sin_y * v->z;
    new_z = -sin_y * v->x + cos_y * v->z;

    v->x = new_x;
    v->z = new_z;

    // Rotate around the Z-axis
    new_x = cos_z * v->x - sin_z * v->y;
    new_y = sin_z * v->x + cos_z * v->y;

    v->x = new_x;
    v->y = new_y;
}


t_vector rotate_around_point(t_vector point, t_vector origin, int theta_x, int theta_y, int theta_z) {
    // Convert angles to radians
    float rad_x = DEG_TO_RAD(theta_x);
    float rad_y = DEG_TO_RAD(theta_y);
    float rad_z = DEG_TO_RAD(theta_z);

    // Translate the point to the origin by subtracting the origin's coordinates
    t_vector translated = {point.x - origin.x, point.y - origin.y, point.z - origin.z};

    // Rotation matrix for X axis
    float cos_x = cos(rad_x);
    float sin_x = sin(rad_x);
    int x_rot = translated.x;
    int y_rot = translated.y * cos_x - translated.z * sin_x;
    int z_rot = translated.y * sin_x + translated.z * cos_x;

    // Rotation matrix for Y axis
    float cos_y = cos(rad_y);
    float sin_y = sin(rad_y);
    int x_rot2 = x_rot * cos_y + z_rot * sin_y;
    int y_rot2 = y_rot;
    int z_rot2 = -x_rot * sin_y + z_rot * cos_y;

    // Rotation matrix for Z axis
    float cos_z = cos(rad_z);
    float sin_z = sin(rad_z);
    int x_rot3 = x_rot2 * cos_z - y_rot2 * sin_z;
    int y_rot3 = x_rot2 * sin_z + y_rot2 * cos_z;
    int z_rot3 = z_rot2;

    // Translate the point back by adding the origin's coordinates
    t_vector rotated = {x_rot3 + origin.x, y_rot3 + origin.y, z_rot3 + origin.z};
    rotated.color = point.color;
    return rotated;
}
