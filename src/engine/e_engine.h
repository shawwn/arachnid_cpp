//========================================================================
//	file:		e_engine.h
//	author:		Shawn Presser 
//	date:		6/30/10
//
// (c) 2010 Shawn Presser.  All Rights Reserved.
//========================================================================
#pragma once

//========================================================================
// Headers
//========================================================================
#include "gr_driver.h"
//========================================================================

//========================================================================
// Declarations
//========================================================================
class EFile;
class GrScene;
class GrCamera;
//========================================================================

//========================================================================
// EEngine
//========================================================================
class ENGINE_API EEngine
{
private:
	GrDriver*			_renderer;
	void*				_rendererLib;
	void*				_rendererLibShutdownFn;

	bool				_done;

	EEngine();
public:
	// specify renderer "none", "gl2", or "d3d9"
	static EEngine*		Create(const wstring& ctx, const wstring& renderer = _TS("none"));
	~EEngine();

	// provides access to the scene objects;
	GrDriver&			GetRenderer()					{ return *_renderer; }
	GrScene&			GetScene()						{ return _renderer->GetScene(); }
	GrCamera&			GetCamera()						{ return _renderer->GetCamera(); }

	// call once per frame.  Returns false if the application should exit.
	bool				PerFrame();
};
extern ENGINE_API EEngine*		gEngine;
//========================================================================
