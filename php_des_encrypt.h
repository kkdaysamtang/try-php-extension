/* des_encrypt extension for PHP */

#ifndef PHP_DES_ENCRYPT_H
# define PHP_DES_ENCRYPT_H

extern zend_module_entry des_encrypt_module_entry;
# define phpext_des_encrypt_ptr &des_encrypt_module_entry

# define PHP_DES_ENCRYPT_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_DES_ENCRYPT)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_DES_ENCRYPT_H */
