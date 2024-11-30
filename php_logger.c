/* php_logger extension for PHP */

#include "zend_API.h"
#include "zend_alloc.h"
#include "zend_frameless_function.h"
#include "zend_string.h"
#include "zend_types.h"
#include <stdlib.h>
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_php_logger.h"
#include "php_logger_arginfo.h"

# define PRINTF_DEBUG(arg) php_printf arg

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

struct php_parse_handler {
	int is_current_use;
	int current_argv_off;
	int main_mem_off;
};

struct php_logger_settings {
	long* 		colored;
	long*		verbose;
};

struct php_logger_settings shared_php_logger_conf;


PHP_FUNCTION(log_trace)
{
	struct php_parse_handler parse_handler;
	memset(&parse_handler, 0, sizeof(parse_handler));

	zval *data = NULL;
	uint32_t argc;
	

	ZEND_PARSE_PARAMETERS_START(1, -1)
		Z_PARAM_VARIADIC('+', data, argc)
	ZEND_PARSE_PARAMETERS_END();

	if (Z_TYPE(data[0]) != IS_STRING) {
		zend_argument_type_error(1, "must be string, %s given", 
			zend_zval_value_name(&data[0])
		);
	} else {
		char *fmt;
		zval is_str_eq;
		size_t arg1len = Z_STRLEN(data[0]);

		int total_alloc = arg1len;
		int found = 0;
		int argv_total_buf = 0;

		for(int i = 0; i < Z_STRLEN(data[0]); i++) {
			if (Z_STRVAL(data[0])[i] == '%' && i < arg1len) {

				found = found + 1;
				
			}
		}

		// PRINTF_DEBUG(("argc - 1: %d\n", argc - 1));
		// PRINTF_DEBUG(("found: %d\n", found));
		

		if ((argc - 1) != found) {
			zend_argument_count_error("%d arguments are required, %d given", found, argc - 1);

			RETURN_NULL();
		} else {

			for(int i = 1; i < argc && argc != 1; i++) {
				argv_total_buf = argv_total_buf + Z_STRLEN(data[i]);
			}

			int fmt_size_trim = arg1len - (found * 2);
			long alloc_mem_len = fmt_size_trim + argv_total_buf;

			// void* allocated_mem = emalloc(alloc_mem_len + 1);
			zend_string *allocated_mem = zend_string_alloc(alloc_mem_len, 0);
			parse_handler.main_mem_off = 0;

			parse_handler.current_argv_off = 1; /* argc started from 1, because indexof 0 it was used as format */

			for(int i = 0; i < Z_STRLEN(data[0]); i++) {

				if (Z_STRVAL(data[0])[i] == '%' && i < arg1len) {
					parse_handler.is_current_use = 1; /* maybe unused */
					
					for(int z = 0; z < Z_STRLEN(data[parse_handler.current_argv_off]) &&
							parse_handler.current_argv_off < argc; z++) 
					{
						/* replace char started by % by actual data */

						ZSTR_VAL(allocated_mem)[parse_handler.main_mem_off] = Z_STRVAL(data[parse_handler.current_argv_off])[z];
						parse_handler.main_mem_off++;

						
					}

					/* after operation, current_argv_off incremented by 1 */
					parse_handler.current_argv_off++;
					
				} else {
					ZSTR_VAL(allocated_mem)[parse_handler.main_mem_off] = Z_STRVAL(data[0])[i];
					parse_handler.main_mem_off++;
				}
			}

			php_printf("%s\n", ZSTR_VAL(allocated_mem));


			efree(allocated_mem);

			RETURN_LONG(alloc_mem_len);
		}


		
	}
	// RETURN_NULL();
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
