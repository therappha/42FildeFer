
#include "../includes/fdf.h"

#include <math.h>  // For cos() and sin()

void rotate_all(t_vector *v, int angle_x, int angle_y, int angle_z)
{
    // Convert angles to radians if necessary (if angles are in degrees)
    float angle_x_rad = angle_x * (M_PI / 180);
    float angle_y_rad = angle_y * (M_PI / 180);
    float angle_z_rad = angle_z * (M_PI / 180);

    // Safety check: ensure no invalid values for trigonometric calculations
    if (isnan(angle_x_rad) || isnan(angle_y_rad) || isnan(angle_z_rad)) {
        printf("Error: Invalid angle values (NaN detected)\n");
        return;  // Exit early if angles are invalid
    }

    // Rotate around the X-axis
    float cos_x = cos(angle_x_rad);
    float sin_x = sin(angle_x_rad);
    float new_y = cos_x * v->y - sin_x * v->z;
    float new_z = sin_x * v->y + cos_x * v->z;
    v->y = new_y;
    v->z = new_z;

    // Rotate around the Y-axis
    float cos_y = cos(angle_y_rad);
    float sin_y = sin(angle_y_rad);
    float new_x = cos_y * v->x + sin_y * v->z;
    v->z = -sin_y * v->x + cos_y * v->z;
    v->x = new_x;

    // Rotate around the Z-axis
    float cos_z = cos(angle_z_rad);
    float sin_z = sin(angle_z_rad);
    new_x = cos_z * v->x - sin_z * v->y;
    float new_y_z = sin_z * v->x + cos_z * v->y;
    v->x = new_x;
    v->y = new_y_z;

    // Preserve the color (no change needed for color)
}



