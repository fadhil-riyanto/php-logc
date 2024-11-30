/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: a85d0d50a0c44762ee3f4ba515e1d5d26efaec1c */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test1, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test2, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, str, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_f, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_log_trace, 0, 0, IS_LONG, 0)
	ZEND_ARG_VARIADIC_TYPE_INFO(0, str_n, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_log_show_config arginfo_test1

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_log_config, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, colored, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, verbose, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(test1);
ZEND_FUNCTION(test2);
ZEND_FUNCTION(test_f);
ZEND_FUNCTION(log_trace);
ZEND_FUNCTION(log_show_config);
ZEND_FUNCTION(log_config);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(test1, arginfo_test1)
	ZEND_FE(test2, arginfo_test2)
	ZEND_FE(test_f, arginfo_test_f)
	ZEND_FE(log_trace, arginfo_log_trace)
	ZEND_FE(log_show_config, arginfo_log_show_config)
	ZEND_FE(log_config, arginfo_log_config)
	ZEND_FE_END
};
