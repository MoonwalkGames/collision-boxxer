#include "Collision.h"
#include <stdio.h>
/*
Collision test functions
- Takes in two types of colliders
- Use the one you need based on the objects your checking
*/
// Same type collision functions
Collision SPHEREvSPHERE(const Col_Sphere& a, const Col_Sphere& b)
{
	float sumRadii = a.radius + b.radius;
	sumRadii *= sumRadii; //Avoids using sqrt

	float distance = (a.position.x + b.position.x) + (a.position.y + b.position.y);
	distance *= distance; //Avoids using sqrt

						  //Returns collision result
	if (distance <= sumRadii)
		return Collision(true, glm::vec3(0.0f));
	else
		return Collision(false, glm::vec3(0.0f));
}
//
//Collision AABBvAABB(const Col_AABB& a, const Col_AABB& b)
//{
//}

Collision CH::OBBvOBB(const Col_OBB& a, const Col_OBB& b)
{
	for (int i = 0; i < 3; i++)
	{
		//Calculating the coord frame we need to use//
		glm::vec3 v;

		if (i == 0)
			v = (a.position + glm::vec3(a.extent.x, 0, 0)) - a.position;
		else if (i == 1)
			v = (a.position + glm::vec3(0, a.extent.y, 0)) - a.position;
		else
			v = (a.position + glm::vec3(0, 0, a.extent.z)) - a.position;
		//printf("Pos: %f, %f, %f\n", a.position.x, a.position.y, a.position.z);
		printf("Ext A: %f, %f, %f\n", a.extent.x, a.extent.y, a.extent.z);
		printf("Ext B: %f, %f, %f\n", b.extent.x, b.extent.y, b.extent.z);

		v = glm::normalize(v);
		//printf("%f, %f, %f\n", v.x, v.y, v.z);
		//End of calculating coord frame

		//Projecting points onto our new coord frame and checking for any overlap//
		glm::vec3 c = b.position - a.position;

		float dotA_V = glm::abs(glm::dot(a.extent, v));
		float dotB_V = glm::abs(glm::dot(b.extent, v));
		float dotC_V = glm::abs(glm::dot(c, v));

		if (dotC_V > (dotA_V + dotB_V))
			return Collision(false, glm::vec3(0.0f));
	}
	//Calculate penetration here//
	//....//
	return Collision(true, glm::vec3(0.0f)); //Return penetration, not zeroed vector
}

//Type A vs Type B
//Collision CH::SPHEREvAABB(const Col_Sphere& a, const Col_AABB& b)
//{
//
//}
//Collision CH::SPHEREvOBB(const Col_Sphere& a, const Col_OBB& b)
//{
//
//}
//Collision CH::AABBvOBB(const Col_AABB& a, const Col_OBB& b)
//{
//
//}

//Type B vs Type A
//Collision CH::AABBvSPHERE(const Col_AABB& a, const Col_Sphere& b) {
//	return SPHEREvAABB(b, a);
//}
//
//Collision CH::OBBvSPHERE(const Col_OBB& a, const Col_Sphere& b) {
//	return SPHEREvOBB(b, a);
//}
//
//Collision CH::OBBvAABB(const Col_OBB& a, const Col_AABB& b) {
//	return AABBvOBB(b, a);
//}