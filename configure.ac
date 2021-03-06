dnl ******************************************************************
dnl  * Copyright (c) 2000-2018, 2019 S.Bhatnagar
dnl  *
dnl #   This file is part of fussy.
dnl #
dnl #   fussy is a free software: you can redistribute it and/or modify
dnl #   it under the terms of the GNU General Public License as published by
dnl #   the Free Software Foundation, either version 3 of the License, or
dnl #   (at your option) any later version.
dnl #
dnl #   fussy is distributed in the hope that it will be useful,
dnl #   but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl #   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl #   GNU General Public License for more details.
dnl #
dnl #   You should have received a copy of the GNU General Public License
dnl #   along with fussy.  If not, see <https://www.gnu.org/licenses/>.

#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(fussy, 2.0, sbhatnag@nrao.edu)
AM_INIT_AUTOMAKE([-Wall subdir-objects])
AC_CONFIG_SRCDIR([src/func.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_YACC
AC_PROG_LEX
AC_PROG_F77
AC_PROG_RANLIB
AM_PROG_AR

# LaTeX for documentation
AC_CHECK_PROG(PDFLATEX, pdflatex, pdflatex)
if test -z "$PDFLATEX"; then
  AC_MSG_WARN([Unable to create PDF version of the user manual.])
fi
AM_CONDITIONAL([HAVE_PDFLATEX], test -n "$PDFLATEX")

# htlatex for documentation
AC_CHECK_PROG(HTLATEX, htlatex, htlatex)
if test -z "$HTLATEX"; then
  AC_MSG_WARN([Unable to create HTML version of the user manual.])
fi
AM_CONDITIONAL([HAVE_HTLATEX], test -n "$HTLATEX")

# Checks for libraries.
AC_CHECK_LIB([history], [main])
AC_CHECK_LIB([m], [floor])
AC_CHECK_LIB([readline], [readline])
AC_CHECK_LIB([readline], [add_history])
AC_CHECK_LIB([termcap], [main])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h sys/time.h unistd.h values.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_PID_T
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([floor gettimeofday pow rint sqrt strerror strstr])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
