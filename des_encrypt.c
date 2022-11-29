/* des_encrypt extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_des_encrypt.h"
#include "des_encrypt_arginfo.h"
#include "DES.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

int time_of_minit;
int time_of_rinit;

/* {{{ void test1() */
PHP_FUNCTION(test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!!!!!\r\n", "des_encrypt");
	php_printf("M_INIT_TIME %d\r\n", time_of_minit);
	php_printf("R_INIT_TIME %d\r\n", time_of_rinit);
}
/* }}} */

/* {{{ string test2( [ string $var ] ) */
PHP_FUNCTION(test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/


PHP_FUNCTION(kkday_encrypt)
{
    char *plain_text = "";
    size_t plain_text_len = sizeof("") - 1;
    zend_string *encrypted;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(plain_text, plain_text_len)
    ZEND_PARSE_PARAMETERS_END();

    encrypted = strpprintf(0, "plain: %s, len: %ld\r\n", plain_text, plain_text_len);

    say();

    RETURN_STR(encrypted);
}

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINIT_FUNCTION(des_encrypt)
{
    #if defined(ZTS) && defined(COMPILE_DL_TEST)
        ZEND_TSRMLS_CACHE_UPDATE();
    #endif
    
    time_of_minit=time(NULL);

    return SUCCESS;
}
/* }}} */


PHP_MSHUTDOWN_FUNCTION(des_encrypt)
{
    return SUCCESS;
}

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(des_encrypt)
{
    #if defined(ZTS) && defined(COMPILE_DL_DES_ENCRYPT)
	ZEND_TSRMLS_CACHE_UPDATE();
    #endif

    time_of_rinit=time(NULL);
    return SUCCESS;
}
/* }}} */

PHP_RSHUTDOWN_FUNCTION(des_encrypt)
{
    return SUCCESS;
}


/* {{{ des_encrypt_module_entry */
zend_module_entry des_encrypt_module_entry = {
	STANDARD_MODULE_HEADER,
	"des_encrypt",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	PHP_MINIT(des_encrypt),							/* PHP_MINIT - Module initialization */
	PHP_MSHUTDOWN(des_encrypt),							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(des_encrypt),			/* PHP_RINIT - Request initialization */
	PHP_RSHUTDOWN(des_encrypt),							/* PHP_RSHUTDOWN - Request shutdown */
	NULL,			/* PHP_MINFO - Module info */
	PHP_DES_ENCRYPT_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_DES_ENCRYPT
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(des_encrypt)
#endif
