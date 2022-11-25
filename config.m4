dnl config.m4 for extension des_encrypt

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use 'with':

dnl PHP_ARG_WITH([des_encrypt],
dnl   [for des_encrypt support],
dnl   [AS_HELP_STRING([--with-des_encrypt],
dnl     [Include des_encrypt support])])

dnl Otherwise use 'enable':

PHP_ARG_ENABLE([des_encrypt],
  [whether to enable des_encrypt support],
  [AS_HELP_STRING([--enable-des_encrypt],
    [Enable des_encrypt support])],
  [no])

if test "$PHP_DES_ENCRYPT" != "no"; then
  dnl Write more examples of tests here...

  dnl Remove this code block if the library does not support pkg-config.
  dnl PKG_CHECK_MODULES([LIBFOO], [foo])
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBS, DES_ENCRYPT_SHARED_LIBADD)

  dnl If you need to check for a particular library version using PKG_CHECK_MODULES,
  dnl you can use comparison operators. For example:
  dnl PKG_CHECK_MODULES([LIBFOO], [foo >= 1.2.3])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo < 3.4])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo = 1.2.3])

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-des_encrypt -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/des_encrypt.h"  # you most likely want to change this
  dnl if test -r $PHP_DES_ENCRYPT/$SEARCH_FOR; then # path given as parameter
  dnl   DES_ENCRYPT_DIR=$PHP_DES_ENCRYPT
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for des_encrypt files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       DES_ENCRYPT_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$DES_ENCRYPT_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the des_encrypt distribution])
  dnl fi

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-des_encrypt -> add include path
  dnl PHP_ADD_INCLUDE($DES_ENCRYPT_DIR/include)

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-des_encrypt -> check for lib and symbol presence
  dnl LIBNAME=DES_ENCRYPT # you may want to change this
  dnl LIBSYMBOL=DES_ENCRYPT # you most likely want to change this

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   AC_DEFINE(HAVE_DES_ENCRYPT_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your des_encrypt library.])
  dnl ], [
  dnl   $LIBFOO_LIBS
  dnl ])

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are not using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $DES_ENCRYPT_DIR/$PHP_LIBDIR, DES_ENCRYPT_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_DES_ENCRYPT_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your des_encrypt library.])
  dnl ],[
  dnl   -L$DES_ENCRYPT_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(DES_ENCRYPT_SHARED_LIBADD)

  dnl In case of no dependencies
  AC_DEFINE(HAVE_DES_ENCRYPT, 1, [ Have des_encrypt support ])

  PHP_NEW_EXTENSION(des_encrypt, des_encrypt.c, $ext_shared)
fi
