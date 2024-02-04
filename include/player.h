/*
 * Declaration for Player type
 * Lien Zhu
 */


#ifndef PLAYER_H
#define PLAYER_H


#include <raylib.h>


/*
// Ray, ray for raycasting
typedef struct Ray {
    Vector3 position;       // Ray position (origin)
    Vector3 direction;      // Ray direction
} Ray;

// RayCollision, ray hit information
typedef struct RayCollision {
    bool hit;               // Did the ray hit something?
    float distance;         // Distance to the nearest hit
    Vector3 point;          // Point of the nearest hit
    Vector3 normal;         // Surface normal of hit
} RayCollision;
*/


typedef struct Player {
    Ray laser;
    Vector2 position;
    float size;
} Player;


#endif // !PLAYER_H
