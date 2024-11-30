/* php_logger extension for PHP */

#ifndef PHP_PHP_LOGGER_H
# define PHP_PHP_LOGGER_H

#include "php.h"
extern zend_module_entry php_logger_module_entry;
# define phpext_php_logger_ptr &php_logger_module_entry

# define PHP_PHP_LOGGER_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_PHP_LOGGER)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

__attribute__ ((visibility("default"))) extern zend_class_entry *logger_config_ctx;

#endif	/* PHP_PHP_LOGGER_H */
