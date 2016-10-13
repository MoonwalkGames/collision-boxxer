#ifndef COLLISION_H
#define COLLISION_H

#include "glm\glm.hpp"
#include "glm\gtx\projection.hpp"

struct Col_Sphere
{
	Col_Sphere(glm::vec3 pos, float rad) : position(pos), radius(rad) {}
	glm::vec3 position;
	float radius;
};

struct Col_AABB
{
	Col_AABB(glm::vec3 pos, glm::vec3 ext) : position(pos), extent(ext) {}
	glm::vec3 position;
	glm::vec3 extent;
};

struct Col_OBB
{
	Col_OBB(glm::vec3 pos, glm::vec3 ext) : position(pos), extent(ext) {}
	glm::vec3 position;
	glm::vec3 extent;
};

struct Collision
{
	Collision(bool _status, glm::vec3 pen) : status(_status), penetration(pen) {}
	bool status;
	glm::vec3 penetration;

	operator bool() const { return status; }
};
class CollisionHandler
{
public:
	//Same Type Collision
	/*static Collision SPHEREvSPHERE(const Col_Sphere& a, const Col_Sphere& b);
	static Collision AABBvAABB(const Col_AABB& a, const Col_AABB& b);*/
	static Collision OBBvOBB(const Col_OBB& a, const Col_OBB& b);

	////Type A vs Type B
	//static Collision SPHEREvAABB(const Col_Sphere& a, const Col_AABB& b);
	//static Collision SPHEREvOBB(const Col_Sphere& a, const Col_OBB& b);
	//static Collision AABBvOBB(const Col_AABB& a, const Col_OBB& b);

	////Type B vs Type A
	//static Collision AABBvSPHERE(const Col_AABB& a, const Col_Sphere& b);
	//static Collision OBBvSPHERE(const Col_OBB& a, const Col_Sphere& b);
	//static Collision OBBvAABB(const Col_OBB& a, const Col_AABB& b);
};
typedef CollisionHandler CH;
#endif