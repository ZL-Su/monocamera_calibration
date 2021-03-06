/**************************************************************************
This file is part of Matrice, an effcient and elegant C++ library.
Copyright(C) 2018, Zhilong(Dgelom) Su, all rights reserved.

This program is free software : you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.
**************************************************************************/
#pragma once
#include <type_traits>

namespace Dgelo {
template<typename T> struct traits {};
template<typename T> struct traits<const T> : traits<T> { using type = T; };
struct MatrixExpr {};
template<typename Derived, typename Expression> struct DenseExprBase {};
template<typename Derived> struct DenseExprBase<Derived, MatrixExpr> {};
template<typename _Ty> struct remove_reference { using type = std::remove_reference<_Ty>; };
template<typename _Ty> struct type_bytes { enum { value = sizeof(_Ty) }; };
template<int _Rows = 0, int _Cols = 0> struct compile_time_size { 
	enum { val_1 = 0x0001, val_2 = 0x0002, val_3 = 0x0003, val_4 = 0x0004 }; 
	//static const int RunTimeDeduceInHost = 0, RunTimeDeduceInDevi = -1;
	//static const int CompileTimeRows = _Rows, CompileTimeCols = _Cols;
	enum { 
		RunTimeDeduceInHost = 0, 
		RunTimeDeduceInDevi = -1,
		CompileTimeRows = _Rows,
		CompileTimeCols = _Cols
	};
};
}
