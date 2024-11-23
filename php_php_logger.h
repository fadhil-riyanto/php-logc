/* php_logger extension for PHP */

#ifndef PHP_PHP_LOGGER_H
# define PHP_PHP_LOGGER_H

extern zend_module_entry php_logger_module_entry;
# define phpext_php_logger_ptr &php_logger_module_entry

# define PHP_PHP_LOGGER_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_PHP_LOGGER)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_PHP_LOGGER_H */
