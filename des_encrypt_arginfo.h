/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 3e79c38dd4083a0335b3276d122ec56c891dd69f */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test1, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test2, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, str, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_kkday_encrypt, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, plainText, IS_STRING, 0)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(test1);
ZEND_FUNCTION(test2);
ZEND_FUNCTION(kkday_encrypt);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(test1, arginfo_test1)
	ZEND_FE(test2, arginfo_test2)
	ZEND_FE(kkday_encrypt, arginfo_kkday_encrypt)
	ZEND_FE_END
};
