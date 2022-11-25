/* des_encrypt extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_des_encrypt.h"
#include "des_encrypt_arginfo.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif
int time_of_rinit; //在RINIT里初始化，看看每次页面请求的时候是否变化。
int time_of_minit;

/* {{{ void test1() */
PHP_FUNCTION(test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!!!!!\r\n", "des_encrypt");
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


PHP_FUNCTION(test_scale)
{
    double x;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(x)
    ZEND_PARSE_PARAMETERS_END();

    php_printf("%d<br />",time_of_minit);
    php_printf("%d<br />",time_of_rinit);

    RETURN_DOUBLE(x * 2);
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


/* {{{ PHP_MINFO_FUNCTION */
PHP_MINIT_FUNCTION(des_encrypt)
{
#if defined(ZTS) && defined(COMPILE_DL_TEST)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif
    time_of_minit=time(NULL); //我们在MINIT启动中对它初始化
    REGISTER_STRINGL_CONSTANT("TEST_SCALE_STRING", "AABBCC", 6,
        CONST_CS | CONST_PERSISTENT);

    REGISTER_LONG_CONSTANT("TEST_SCALE_FACTOR", 2,
        CONST_CS | CONST_PERSISTENT);
    return SUCCESS;
}
/* }}} */

PHP_RSHUTDOWN_FUNCTION(des_encrypt)
{
    //FILE *fp=fopen("tttt/time_rshutdown.txt","a+");
    //fprintf(fp,"%ld\n",time(NULL)); //让我们看看是不是每次请求结束都会在这个文件里追加数据
    //fclose(fp);
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(des_encrypt)
{
    //FILE *fp=fopen("~/dev/des_encrypt/tttt/time_mshutdown.txt","a+"); //请确保文件可写，否则apache会莫名崩溃
    //fprintf(fp,"%ld\n",time(NULL));
    return SUCCESS;
}

/* {{{ des_encrypt_module_entry */
zend_module_entry des_encrypt_module_entry = {
	STANDARD_MODULE_HEADER,
	"des_encrypt",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	PHP_MINIT(des_encrypt),							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(des_encrypt),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
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
