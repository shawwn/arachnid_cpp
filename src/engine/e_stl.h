//========================================================================
//	file:		e_stl.h
//	author:		Shawn Presser 
//	date:		6/30/10
//
// (c) 2010 Shawn Presser.  All Rights Reserved.
//========================================================================
#pragma once

//========================================================================
// Headers
//========================================================================
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>
//========================================================================

//========================================================================
// Containers
//========================================================================
using std::string;
using std::wstring;
using std::vector;
using std::list;
using std::map;
using std::set;
using stdext::hash_map;
using stdext::hash_set;

typedef vector<string>		strvec;
typedef vector<wstring>		wstrvec;
//========================================================================

//========================================================================
// Declarations
//========================================================================
#define SNULL				""
#define WSNULL				L""
#define _T_pre(x)			L##x
#define _T(x)				_T_pre(x)
//========================================================================
