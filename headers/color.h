#pragma once
typedef struct color {
    float red;
    float green;
    float blue;
    float alpha;
} color;

color * create_color(int red, int green, int blue, float alpha);