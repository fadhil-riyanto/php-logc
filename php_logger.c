/* php_logger extension for PHP */

#include "zend_API.h"
#include "zend_frameless_function.h"
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_php_logger.h"
#include "php_logger_arginfo.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void test1() */
PHP_FUNCTION(test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "php_logger");
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



PHP_FUNCTION(test_f)
{
	double y;

	ZEND_PARSE_PARAMETERS_START(1, 1)	
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_DOUBLE(y * 2);
}

/* }}}*/

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(php_logger)
{
#if defined(ZTS) && defined(COMPILE_DL_PHP_LOGGER)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(php_logger)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "php_logger support", "enabled");
	php_info_print_table_end();
}
/* }}} */

// static const zend_function_entry test_function[] = {
// 	PHP_FE(test1, arginfo_test1)
// 	PHP_FE(test2, arginfo_test2)
// 	PHP_FE(test_f, arginfo_test_f)
// 	PHP_FE_END
// }

/* {{{ php_logger_module_entry */
zend_module_entry php_logger_module_entry = {
	STANDARD_MODULE_HEADER,
	"php_logger",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(php_logger),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(php_logger),			/* PHP_MINFO - Module info */
	PHP_PHP_LOGGER_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PHP_LOGGER
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(php_logger)
#endif
