#pragma once

struct Vector
{
	void operator+=(Vector const& otherVector);
	void operator-=(Vector const& otherVector);
	Vector operator*(float coefficient) const;
	static Vector createFromAngle(float norm, float angleInDegree);
	float x{ 0.f };
	float y{ 0.f };

	static const float PI;
};

