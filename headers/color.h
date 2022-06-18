#pragma once
typedef struct color {
    int red;
    int green;
    int blue;
    float alpha;
} color;

color * createColor(int red, int green, int blue, float alpha);