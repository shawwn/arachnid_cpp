//========================================================================
//	file:		m_mat44.h
//	author:		Shawn Presser 
//	date:		6/30/10
//
// (c) 2010 Shawn Presser.  All Rights Reserved.
//========================================================================
#pragma once

//========================================================================
// Declarations
//========================================================================
class MVec3;
class MMat33;
//========================================================================

//========================================================================
// MMat44
//========================================================================
class MMat44
{
private:
	float	_v[16];

public:
	MMat44();
	MMat44(	float _00, float _10, float _20, float _30,
			float _01, float _11, float _21, float _31,
			float _02, float _12, float _22, float _32,
			float _03, float _13, float _23, float _33 );
	MMat44(const float* p)							{ Set(p); }

	static MMat44	IdentityMat;
	void			Identity();

	MVec3			TransformNoPersp(const MVec3& v);
	void			TransformNoPersp(MVec3& v);

	const float*	Get() const						{ return _v; }
	void			Set(const float* p);

	float			Get(int col, int row) const		{ return (*this)(col, row); }
	float&			Get(int col, int row)			{ return (*this)(col, row); }

	MVec3			GetTransform() const;
	void			SetTransform(const MVec3& t);

	MMat33			GetRot() const;
	void			SetRot(const MMat33& r);

	float			operator()(int col, int row) const;
	float&			operator()(int col, int row);

	MMat44			operator *(const MMat44& m);
	MMat44&			operator *=(const MMat44& m);
};
//========================================================================
