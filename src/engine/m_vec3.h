//========================================================================
//	file:		m_vec3.h
//	author:		Shawn Presser 
//	date:		6/30/10
//
// (c) 2010 Shawn Presser.  All Rights Reserved.
//========================================================================
#pragma once

//========================================================================
// MVec3
//========================================================================
class ENGINE_API MVec3
{
private:
	float	_v[3];

public:
	// ctors.
	MVec3()										{ /* not initialized */ }
	MVec3(const MVec3& v)						{ Set(v); }
	MVec3(const float* p)						{ Set(p); }
	MVec3(float s)								{ Set(s, s, s); }
	MVec3(float x, float y, float z)			{ Set(x, y, z); }

	// identity / zero.
	static MVec3	Zero;
	void			SetZero()					{ Set(Zero); }

	// accessors.
	float			X() const					{ return _v[0]; }
	float&			X()							{ return _v[0]; }
	float			Y() const					{ return _v[1]; }
	float&			Y()							{ return _v[1]; }
	float			Z() const					{ return _v[2]; }
	float&			Z()							{ return _v[2]; }
	float*			Get()						{ return _v;	}
	const float*	Get() const					{ return _v; }
	float			Get(uint idx) const			{ E_ASSERT(idx < 3); return _v[idx]; }
	float&			Get(uint idx) 				{ E_ASSERT(idx < 3); return _v[idx]; }
	float			operator()(uint idx) const	{ E_ASSERT(idx < 3); return _v[idx]; }
	float&			operator()(uint idx) 		{ E_ASSERT(idx < 3); return _v[idx]; }

	// setters.
	void			SetX(float v)				{ _v[0] = v; }
	void			SetY(float v)				{ _v[1] = v; }
	void			SetZ(float v)				{ _v[2] = v; }
	void			Set(float x, float y, float z);
	void			Set(const float* p);
	void			Set(const MVec3& v);
	MVec3&			operator =(const MVec3& v);

	// vector operations.
	float			MagSqr() const;
	float			Mag() const;
	float			Dot(const MVec3& v);

	// normalizes this vector and returns the previous magnitude.
	float			Normalize();

	// computes a normalized vector from this vector to the specified vector.
	//		normalize(pt - *this)
	MVec3			Dir(const MVec3& pt);

	// computes the cross-product of this vector with the specified vector.
	//		cross(this, v)
	MVec3			Cross(const MVec3& v) const;

	// Let	A = this vector
	//		B = the specified vector
	//		T = a value in the range [0.0 .. 1.0]
	//
	// When T is 0.0, the result is A.  When T is 1.0, the result is B.
	// Otherwise, the result is the interpolation from A to B by T.
	//
	// For example, T = 0.25 would result in a point which is one-quarter
	// the way from A to B (three times further from B than from A).
	MVec3			Blend(const MVec3& dest, float t) const;

	// arithmetic operators.
	MVec3			operator -() const;

	MVec3			operator +(const MVec3& v) const;
	MVec3&			operator +=(const MVec3& v);

	MVec3			operator -(const MVec3& v) const;
	MVec3&			operator -=(const MVec3& v);

	friend ENGINE_API MVec3		operator *(float s, const MVec3& v);
	MVec3&						operator *=(float s);

	// comparison.  Returns true if we are equivalent to the specified vector
	// (within floating-point roundoff tolerances).
	bool			operator ==(const MVec3& v) const;
	bool			Compare(const MVec3& v, float epsilon) const;
};
//========================================================================


