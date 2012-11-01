/*
 * Copyright (c) 2012 Andreas Fett.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
	yet another template header

	Typelist and other Metaprogramming Utilities

	The evaluation result of template classes evaluating to
	an integer/bool value is an enum element with name "value".

	The evaluation result of template classes evaluating to
	a type is a typedef with name "type".
*/

namespace yath {

// evaluate to 1 if T0 == T1 otherwise 0
template <typename T0, typename T1>
struct type_equal {
	enum { value = 0 };
};

template <typename T0>
struct type_equal<T0, T0> {
	enum { value = 1 };
};

// evaluate to  T0 if Cond == true else to T1
template <bool Cond, typename T0, typename T1>
struct type_if {
	typedef T0 type;
};

template <typename T0, typename T1>
struct type_if<false, T0, T1> {
	typedef T1 type;
};

// Nil type to terminate type lists
struct Nil { };

// Cons cell to build type lists
template <typename Car, typename Cdr = Nil >
struct Cons {
	typedef Car car;
	typedef Cdr cdr;
};

// evaluate to number of consecutive not Nil types in TypeList
template <typename TypeList>
struct size_of {
	enum { value = size_of<typename TypeList::cdr>::value + 1 };
};

template <>
struct size_of<Nil> {
	enum { value = 0 };
};

// evaluate to the index of the first occurence of T in TypeList
template <typename T, typename TypeList, int Idx = 0>
struct index_of {
	enum { value = index_of<T, typename TypeList::cdr, Idx + 1>::value };
};

template <typename T, typename Cdr, int Idx>
struct index_of<T, Cons<T, Cdr>, Idx> {
	enum { value = Idx };
};

// evaluate to the type found at index Idx in TypeList
template <typename TypeList, int Idx>
struct type_at {
	typedef typename type_at<typename TypeList::cdr, Idx - 1>::type type;
};

template <typename TypeList>
struct type_at<TypeList, 0> {
	typedef typename TypeList::car type;
};

// evaluate to Cons< T0, Cdr> if T0 is not Nil, to Nil otherwise
template <typename T0, typename Cdr>
struct cons_if {
	typedef Cons<T0, Cdr> type;
};

template <typename Cdr>
struct cons_if <Nil, Cdr> {
	typedef Nil type;
};

// Generate a type list of all consecutive template parameters which are not Nil
// gcc version 4.4.5 (Debian 4.4.5-8) will do template recursion
// to a depth of 500 on my system by default. YMMV.
template <
	typename   T0      , typename   T1 = Nil, typename   T2 = Nil, typename   T3 = Nil,
	typename   T4 = Nil, typename   T5 = Nil, typename   T6 = Nil, typename   T7 = Nil,
	typename   T8 = Nil, typename   T9 = Nil, typename  T10 = Nil, typename  T11 = Nil,
	typename  T12 = Nil, typename  T13 = Nil, typename  T14 = Nil, typename  T15 = Nil,
	typename  T16 = Nil, typename  T17 = Nil, typename  T18 = Nil, typename  T19 = Nil,
	typename  T20 = Nil, typename  T21 = Nil, typename  T22 = Nil, typename  T23 = Nil,
	typename  T24 = Nil, typename  T25 = Nil, typename  T26 = Nil, typename  T27 = Nil,
	typename  T28 = Nil, typename  T29 = Nil, typename  T30 = Nil, typename  T31 = Nil,
	typename  T32 = Nil, typename  T33 = Nil, typename  T34 = Nil, typename  T35 = Nil,
	typename  T36 = Nil, typename  T37 = Nil, typename  T38 = Nil, typename  T39 = Nil,
	typename  T40 = Nil, typename  T41 = Nil, typename  T42 = Nil, typename  T43 = Nil,
	typename  T44 = Nil, typename  T45 = Nil, typename  T46 = Nil, typename  T47 = Nil,
	typename  T48 = Nil, typename  T49 = Nil, typename  T50 = Nil, typename  T51 = Nil,
	typename  T52 = Nil, typename  T53 = Nil, typename  T54 = Nil, typename  T55 = Nil,
	typename  T56 = Nil, typename  T57 = Nil, typename  T58 = Nil, typename  T59 = Nil,
	typename  T60 = Nil, typename  T61 = Nil, typename  T62 = Nil, typename  T63 = Nil,
	typename  T64 = Nil, typename  T65 = Nil, typename  T66 = Nil, typename  T67 = Nil,
	typename  T68 = Nil, typename  T69 = Nil, typename  T70 = Nil, typename  T71 = Nil,
	typename  T72 = Nil, typename  T73 = Nil, typename  T74 = Nil, typename  T75 = Nil,
	typename  T76 = Nil, typename  T77 = Nil, typename  T78 = Nil, typename  T79 = Nil,
	typename  T80 = Nil, typename  T81 = Nil, typename  T82 = Nil, typename  T83 = Nil,
	typename  T84 = Nil, typename  T85 = Nil, typename  T86 = Nil, typename  T87 = Nil,
	typename  T88 = Nil, typename  T89 = Nil, typename  T90 = Nil, typename  T91 = Nil,
	typename  T92 = Nil, typename  T93 = Nil, typename  T94 = Nil, typename  T95 = Nil,
	typename  T96 = Nil, typename  T97 = Nil, typename  T98 = Nil, typename  T99 = Nil,
	typename T100 = Nil, typename T101 = Nil, typename T102 = Nil, typename T103 = Nil,
	typename T104 = Nil, typename T105 = Nil, typename T106 = Nil, typename T107 = Nil,
	typename T108 = Nil, typename T109 = Nil, typename T110 = Nil, typename T111 = Nil,
	typename T112 = Nil, typename T113 = Nil, typename T114 = Nil, typename T115 = Nil,
	typename T116 = Nil, typename T117 = Nil, typename T118 = Nil, typename T119 = Nil,
	typename T120 = Nil, typename T121 = Nil, typename T122 = Nil, typename T123 = Nil,
	typename T124 = Nil, typename T125 = Nil, typename T126 = Nil, typename T127 = Nil
>
struct type_list
{
	typedef Cons< T0,
		typename cons_if <   T1, typename cons_if <   T2, typename cons_if <   T3, typename cons_if <   T4,
		typename cons_if <   T5, typename cons_if <   T6, typename cons_if <   T7, typename cons_if <   T8,
		typename cons_if <   T9, typename cons_if <  T10, typename cons_if <  T11, typename cons_if <  T12,
		typename cons_if <  T13, typename cons_if <  T14, typename cons_if <  T15, typename cons_if <  T16,
		typename cons_if <  T17, typename cons_if <  T18, typename cons_if <  T19, typename cons_if <  T20,
		typename cons_if <  T21, typename cons_if <  T22, typename cons_if <  T23, typename cons_if <  T24,
		typename cons_if <  T25, typename cons_if <  T26, typename cons_if <  T27, typename cons_if <  T28,
		typename cons_if <  T29, typename cons_if <  T30, typename cons_if <  T31, typename cons_if <  T32,
		typename cons_if <  T33, typename cons_if <  T34, typename cons_if <  T35, typename cons_if <  T36,
		typename cons_if <  T37, typename cons_if <  T38, typename cons_if <  T39, typename cons_if <  T40,
		typename cons_if <  T41, typename cons_if <  T42, typename cons_if <  T43, typename cons_if <  T44,
		typename cons_if <  T45, typename cons_if <  T46, typename cons_if <  T47, typename cons_if <  T48,
		typename cons_if <  T49, typename cons_if <  T50, typename cons_if <  T51, typename cons_if <  T52,
		typename cons_if <  T53, typename cons_if <  T54, typename cons_if <  T55, typename cons_if <  T56,
		typename cons_if <  T57, typename cons_if <  T58, typename cons_if <  T59, typename cons_if <  T60,
		typename cons_if <  T61, typename cons_if <  T62, typename cons_if <  T63, typename cons_if <  T64,
		typename cons_if <  T65, typename cons_if <  T66, typename cons_if <  T67, typename cons_if <  T68,
		typename cons_if <  T69, typename cons_if <  T70, typename cons_if <  T71, typename cons_if <  T72,
		typename cons_if <  T73, typename cons_if <  T74, typename cons_if <  T75, typename cons_if <  T76,
		typename cons_if <  T77, typename cons_if <  T78, typename cons_if <  T79, typename cons_if <  T80,
		typename cons_if <  T81, typename cons_if <  T82, typename cons_if <  T83, typename cons_if <  T84,
		typename cons_if <  T85, typename cons_if <  T86, typename cons_if <  T87, typename cons_if <  T88,
		typename cons_if <  T89, typename cons_if <  T90, typename cons_if <  T91, typename cons_if <  T92,
		typename cons_if <  T93, typename cons_if <  T94, typename cons_if <  T95, typename cons_if <  T96,
		typename cons_if <  T97, typename cons_if <  T98, typename cons_if <  T99, typename cons_if < T100,
		typename cons_if < T101, typename cons_if < T102, typename cons_if < T103, typename cons_if < T104,
		typename cons_if < T105, typename cons_if < T106, typename cons_if < T107, typename cons_if < T108,
		typename cons_if < T109, typename cons_if < T110, typename cons_if < T111, typename cons_if < T112,
		typename cons_if < T113, typename cons_if < T114, typename cons_if < T115, typename cons_if < T116,
		typename cons_if < T117, typename cons_if < T118, typename cons_if < T119, typename cons_if < T120,
		typename cons_if < T121, typename cons_if < T122, typename cons_if < T123, typename cons_if < T124,
		typename cons_if < T125, typename cons_if < T126, typename cons_if < T127, Nil >::type
			>::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type
			>::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type
			>::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type
			>::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type
			>::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type
			>::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type
			>::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type
			>::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type
			>::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type >::type
			>::type >::type >::type >::type >::type>::type>::type>::type >::type>::type>::type>::type
			>::type>::type>::type>::type >::type>::type> type;
};

} // namespace yath
