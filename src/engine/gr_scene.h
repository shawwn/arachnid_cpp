//========================================================================
//	file:		gr_scene.h
//	author:		Shawn Presser 
//	date:		7/2/10
//
// (c) 2010 Shawn Presser.  All Rights Reserved.
//========================================================================
#pragma once

//========================================================================
// Declarations
//========================================================================
class GrModel;
//========================================================================

//========================================================================
// GrScene
//========================================================================
class GrScene
{
private:
	wstring			_name;
	GrModel*		_model;
public:
	GrScene(const wstring& name);
	~GrScene();

	const wstring&			GetName() const		{ return _name; }

	GrModel&				GetModel()			{ return *_model; }
	const GrModel&			GetModel() const	{ return *_model; }
};
//========================================================================
